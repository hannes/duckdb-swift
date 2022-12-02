import duckdb_swift
import TabularData

@main
@available(macOS,introduced:12)

public struct duckdb_swift_example {

    public static func main() throws {
        let db = try Database().connect()
        let stmt = try Statement(db, "SELECT range::INTEGER r1, (range+100)::BIGINT r2, range::DOUBLE r3, (range % 2) = 0 r4, range::VARCHAR r5 from range(10) union all select null, null, null, null, null")
         try print(stmt.run())
        
        try print(db.execute("SELECT 42"))
        
        try print(db.execute("SELECT 'XX123456789012344566XX'"))

    }
}

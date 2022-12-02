//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/planner/expression/bound_unnest_expression.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/planner/expression.hpp"

namespace duckdb {

//! Represents a function call that has been bound to a base function
class BoundUnnestExpression : public Expression {
public:
	explicit BoundUnnestExpression(LogicalType return_type);

	unique_ptr<Expression> child;

public:
	bool IsFoldable() const override;
	string ToString() const override;

	hash_t Hash() const override;
	bool Equals(const BaseExpression *other) const override;

	unique_ptr<Expression> Copy() override;

	void Serialize(FieldWriter &writer) const override;
	static unique_ptr<Expression> Deserialize(ExpressionDeserializationState &state, FieldReader &reader);
};
} // namespace duckdb
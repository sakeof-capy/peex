# Data Sources

## Trainee Applied Engineer
- Selects data from a database using query language
    - [Evidence](./evidence/distributed_systems_labs/lab2-3/lab3/clickhouse/queries.sql#L40)

## Junior Applied Engineer
- Orders and groups data from a database using query language
    - [Evidence](./evidence/distributed_systems_labs/lab2-3/lab3/clickhouse/queries.sql#L40)
- Uses database data aggregation techniques to optimise data analysis
    - [Evidence](./evidence/distributed_systems_labs/lab2-3/lab3/clickhouse/queries.sql#L40)
    - ![Benchmarks](benches.png)

## Middle Applied Engineer
- Combines multiple queries to optimise query execution
    - [Info](./COMBINING_QUERIES.md)
- Implements and modifies database structure
    - [Evidence](../1_libraries/evidence/orm_example/migration/src/m20220101_000001_create_table.rs)
    - [Evidence](./evidence/distributed_systems_labs/lab2-3/lab2/postgresql/up.sql)
- Wraps queries into transactions to ensure data consistency and integrity
    - [Info](./TRANSACTIONS.md)

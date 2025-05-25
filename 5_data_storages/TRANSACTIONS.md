Optional Technical Add-On:

    "For example, in PostgreSQL I might write:

BEGIN;
UPDATE accounts SET balance = balance - 100 WHERE id = 1;
UPDATE accounts SET balance = balance + 100 WHERE id = 2;
COMMIT;

If any step fails, I can ROLLBACK to keep the data consistent."


ACID:
Summary Table:
ACID Property	Meaning	                                    Why it Matters
Atomicity	    All-or-nothing execution	                Prevents partial updates
Consistency	    Valid state before and after transaction	Preserves rules and data integrity
Isolation	    Transactions don’t conflict	                Prevents race conditions and dirty reads
Durability	    Changes are permanent after commit	        Ensures reliability even after system failures

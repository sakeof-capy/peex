TDD - write UTs first to define the behavior of the software and then write the software that passes the tests. Only developers are involved.

BDD - at the top level define some end-to-end (E2E) test cases expressed in formalized natural language (Cucumber) which is mapped to the tests in the code automatically. Makes the E2E behaviour of the software. Allows involving less technical stake-holders to the same page of behaviour discussion. For developers, QA and business.

ATDD - aims to collaboratively define the acceptance criteria of the software at the top abstract level (E2E, just like BDD). It might be expressed in natural formalized language (be a form of BDD), but that's not required. If expressed not in natural language, then just test in code is written. But usually we use something like Cucumber for ATDD For developers, QA and business.

Practice	Focus Level	                                                       Example
TDD	    Low-level (unit, code structure)	                                   "This function should return X"
ATDD	High-level (E2E, system behavior)	                                   "A user can reset their password"
BDD	    Similar to ATDD, but emphasizes natural-language specs (e.g. Gherkin)  "Given, When, Then" scenarios

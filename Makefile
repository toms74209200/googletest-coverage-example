TEST_PROJECT := GoogleTest

.PHONY: test

test:
	cmake -S . -B build
	cmake --build build
	find build -maxdepth 1 -name "$(TEST_PROJECT)" -exec {} +

.PHONY: coverage

cov: test
	gcovr

cov-html:
	gcovr --html-details coverage.html
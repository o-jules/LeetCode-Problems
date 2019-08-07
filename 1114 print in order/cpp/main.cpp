class Foo {
public:
    int step = 0;
    function<void()> printSecond;
    function<void()> printThird;

    Foo() {

    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        this->step = 1;
        if (this->printSecond != NULL) {
            this->second(this->printSecond);
        }
    }

    void second(function<void()> printSecond) {
        if (!this->firstHasRun()) {
            this->printSecond = printSecond;
            return;
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        this->step = 2;
        if (this->printThird != NULL) {
            this->third(this->printThird);
        }
    }

    void third(function<void()> printThird) {
        if (!this->secondHasRun()) {
            this->printThird = printThird;
            return;
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();

        this->step = 3;
    }

    bool firstHasRun() {
        return this->step >= 1;
    }

    bool secondHasRun() {
        return this->step >= 2;
    }
};

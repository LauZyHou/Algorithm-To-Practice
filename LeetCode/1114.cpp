class Foo {
private:
	pthread_mutex_t m2;//second要获得的锁
	pthread_mutex_t m3;//third要获得的锁

public:
    Foo() {
		//初始化两个锁
        pthread_mutex_init(&m2,nullptr);
		pthread_mutex_init(&m3,nullptr);
		//加锁
		pthread_mutex_lock(&m2);
		pthread_mutex_lock(&m3);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
		//运行完为2解锁
		pthread_mutex_unlock(&m2);
    }

    void second(function<void()> printSecond) {
        //要运行需获取2的锁
		pthread_mutex_lock(&m2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
		//运行完为3解锁
		pthread_mutex_unlock(&m3);
    }

    void third(function<void()> printThird) {
        //要运行需获取3的锁
		pthread_mutex_lock(&m3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
//
// Created by thoma on 06/08/2023.
//

#ifndef TP_ROGUE_LIKE_THREAD_H
#define TP_ROGUE_LIKE_THREAD_H

#include <chrono>
#include <atomic>
#include <thread>
#include <iostream>
#include <future>

class Thread {
public:
    Thread() = default;
    ~Thread();
    Thread(Thread const& other) = delete;
    Thread(Thread&& other) = default;
    Thread& operator=(Thread const& other) = delete;
    Thread& operator=(Thread&& other) = default;

    void start();
    void stop();
    void join();

protected:
    virtual void run(std::future<void> const& stop_token) = 0;

    static bool is_stop_requested(std::future<void> const& token) noexcept {
        if (token.valid()) {
            auto status = token.wait_for(std::chrono::milliseconds{ 0 });
            if (std::future_status::timeout != status) {
                return true;
            }
        }

        return false;
    }

private:
    std::thread thread_;
    std::promise<void> stop_request_;
};


#endif //TP_ROGUE_LIKE_THREAD_H

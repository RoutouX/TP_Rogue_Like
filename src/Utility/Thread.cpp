//
// Created by thoma on 06/08/2023.
//

#include "Thread.h"

Thread::~Thread() {
    Thread::join();
}

void Thread::start(){
        if (!thread_.joinable()) {
            stop_request_ = std::promise<void>();
            thread_ = std::thread(
                    &Thread::run, this,
                    std::move(stop_request_.get_future())
            );
        }
}

void Thread::stop(){
    try {
        stop_request_.set_value();
    } catch (std::future_error const& ex) {
        // ignore exception in case of multiple calls to 'stop' function
    }
}

void Thread::join(){
    if (thread_.joinable()) {
        thread_.join();
    }
}


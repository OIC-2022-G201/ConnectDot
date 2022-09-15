// @file IObservable.h
// @brief 
// @author ICE
// @date 2022/09/13
// 
// @details

#pragma once
#include <memory>
#include <utility>

#include "IObserver.h"

namespace observable
{
    template<class T>
    class IObservable
    {
    public:
        virtual ~IObservable() = default;
        void virtual Subscribe(IObserverPtr<T> observer) = 0;
        IObserverPtr<T> virtual Subscribe(Action<T> observer) = 0;
        virtual void Dispose(IObserverPtr<T> observer) = 0;
    };
}

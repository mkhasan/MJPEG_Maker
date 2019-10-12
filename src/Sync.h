/**
    \file Sync.h
    \brief null mutex for list and hash map
    \author  SoonYong Jeong
    \version 0.1
    \date 2012.05.10
    \see
    \details
*/

#ifndef __SYNC_H__
#define __SYNC_H__

#include "ace/Condition_Thread_Mutex.h"



/// \brief 잠금 없는 Null mutex
/// \details List나 HashTable등의 Template 기반 데이터 구조를 잠금 없이 사용하기 위한 Mutex class
class NullMutex
{
public:
    /// Default 생성자
    NullMutex(){}
    /// Null mutex pointer 생성자
    NullMutex(NullMutex *){}
    /// acquire lock
    int acquire(void){return 0;}
    /// try to acquire lock
    int tryacquire(void){return 0;}
    /// relase lock
    int release(void){ return 0;}
};

/// Automatic lock
/** AutoLock 객체의 수명주기 내에 lock을 확보하고 있다가 자동적으로 lock을 release하는 클래스
    \par Example
    아래는 AutoLock클래스를 이용하여 thread-safe하게 A클래스의 객체의 Func1를 이용할 수 있게 구현한 간단한 예제다.
    \code
    class A
    {
        Mutex mtx;
    public:
        int Func1()
        {
            AutoLock guard(&mtx);
            ...
            return 0;
            ...
            return -1;
        }
    };
    \endcode
*/
template<class MUTEX>
class AutoLock
{
    MUTEX *lock;
    bool locked;
public:
    /// 생성자
    /** \param mtx lock 객체 포인터
        \param acquire_ AutoLock 시작시 aquire할지 여부. true로 설정하면 생성자 코드 라인부터 mtx에 의해 보호된다.
    */
    AutoLock(MUTEX *mtx, bool acquire_ = true):lock(mtx), locked(false)
    {
        if (acquire_)
        {
            lock->acquire();
            locked = true;
        }
    }
    /// lock 획득 함수
    /// \details 생성자에서 lock을 acquire하지 않은 상태로 시작하거나
    ///     중간에 release한 lock을 새롭게 acquire 할 수 있다.
    void acquire()
    {
        if (!locked)
        {
            lock->acquire();
            locked = true;
        }
    }

    /// lock 해제 함수
    /// \details 중간에 lock을 해제해야할 경우 사용할 수 있다.
    void release()
    {
        if (locked)
        {
            lock->release();
            locked = false;
        }
    }
    /// 소멸자
    /// \details lock을 해제한다.
    ~AutoLock()
    {
        this->release();
    }
};


/// Mutex를 포함한 Thread Condition
/*
class Condition : public ACE_Condition<ACE_Thread_Mutex>
{
    typedef ACE_Condition<ACE_Thread_Mutex> super;
    ACE_Thread_Mutex _lock;
public:
    Condition() : super(_lock){}
};
*/

typedef AutoLock<ACE_Thread_Mutex> ThreadAutoLock;



#endif //__SYNC_H__

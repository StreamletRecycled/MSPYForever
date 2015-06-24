//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlTuple.h
//    Author:      Streamlet
//    Create Time: 2011-04-23
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __XLTUPLE_H_4720D247_760A_43F2_9611_6673153C5C68_INCLUDED__
#define __XLTUPLE_H_4720D247_760A_43F2_9611_6673153C5C68_INCLUDED__


#include "../Meta/xlStaticAssert.h"
#include "../Meta/xlTypeTraits.h"
#include "../xlDef.h"

namespace xl
{
// #ifndef XL_TUPLE_DEFINE_MAX
// #define XL_TUPLE_DEFINE_MAX  20
// #endif
// 
// #define XL_TUPLE_TYPENAME_DECLARE_NT_PATTERN(n)     typename T##n = NullType
// #define XL_TUPLE_TYPENAME_DECLARE_NT(n)             XL_REPZ(XL_TUPLE_TYPENAME_DECLARE_NT_PATTERN, n, XL_COMMA)
// 
// #define XL_TUPLE_TYPENAME_DECLARE_PATTERN(n)        typename T##n
// #define XL_TUPLE_TYPENAME_DECLARE(n)                XL_REPZ(XL_TUPLE_TYPENAME_DECLARE_PATTERN, n, XL_COMMA)
// 
// #define XL_TUPLE_MEMBER_DECLARE_PATTERN(n)          T##n _##n;
// #define XL_TUPLE_MEMBER_DECLARE(n)                  XL_REPZ(XL_TUPLE_MEMBER_DECLARE_PATTERN, n, XL_NIL)
// 
// #define XL_TUPLE_TYPENAME_LIST_PATTERN(n)           T##n
// #define XL_TUPLE_TYPENAME_LIST(n)                   XL_REPZ(XL_TUPLE_TYPENAME_LIST_PATTERN, n, XL_COMMA)
// 
// #define XL_TUPLE_TYPENAME_VARIABLE_PATTERN(n)       T##n _##n
// #define XL_TUPLE_TYPENAME_VARIABLE(n)               XL_REPZ(XL_TUPLE_TYPENAME_VARIABLE_PATTERN, n, XL_COMMA)
// 
// #define XL_TUPLE_INITIALIZE_LIST_PATTERN(n)         _##n(_##n)
// #define XL_TUPLE_INITIALIZE_LIST(n)                 XL_REPZ(XL_TUPLE_INITIALIZE_LIST_PATTERN, n, XL_COMMA)
// 
// #define XL_TUPLE_INITIALIZE_LIST_COPY_PATTERN(n)    _##n(that._##n)
// #define XL_TUPLE_INITIALIZE_LIST_COPY(n)            XL_REPZ(XL_TUPLE_INITIALIZE_LIST_COPY_PATTERN, n, XL_COMMA)
// 
// #define XL_TUPLE_ASSIGN_PATTERN(n)                  this->_##n = that._##n;
// #define XL_TUPLE_ASSIGN(n)                          XL_REPZ(XL_TUPLE_ASSIGN_PATTERN, n, XL_NIL)
// 
// #define XL_TUPLE_EQUAL_PATTERN(n)                   this->_##n == that._##n
// #define XL_TUPLE_EQUAL(n)                           XL_REPZ(XL_TUPLE_EQUAL_PATTERN, n, &&)
// 
// #define XL_TUPLE_NOT_EQUAL_PATTERN(n)               this->_##n != that._##n
// #define XL_TUPLE_NOT_EQUAL(n)                       XL_REPZ(XL_TUPLE_NOT_EQUAL_PATTERN, n, ||)
// 
// #define XL_TUPLE_LITTER_PATTERN(n)                  if (this->_##n < that._##n)         \
//                                                     {                                   \
//                                                         return true;                    \
//                                                     }                                   \
//                                                     else if (that._##n < this->_##n)    \
//                                                     {                                   \
//                                                         return false;                   \
//                                                     }
// #define XL_TUPLE_LITTER(n)                          XL_REPZ(XL_TUPLE_LITTER_PATTERN, n, XL_NIL)
// 
// #define XL_TUPLE_GREATER_PATTERN(n)                 if (this->_##n > that._##n)         \
//                                                     {                                   \
//                                                         return true;                    \
//                                                     }                                   \
//                                                     else if (that._##n > this->_##n)    \
//                                                     {                                   \
//                                                         return false;                   \
//                                                     }
// #define XL_TUPLE_GREATER(n)                         XL_REPZ(XL_TUPLE_GREATER_PATTERN, n, XL_NIL)
// 
//     template <XL_TUPLE_TYPENAME_DECLARE_NT(XL_INC(XL_TUPLE_DEFINE_MAX))>
//     class Tuple;
// 
// #define XL_TUPLE_IMPLEMENT_PATTERN(n)               \
//                                                     \
//     template <XL_TUPLE_TYPENAME_DECLARE(n)>         \
//     class Tuple<XL_TUPLE_TYPENAME_LIST(n)>          \
//     {                                               \
//     public:                                         \
//         XL_TUPLE_MEMBER_DECLARE(n)                  \
//                                                     \
//     public:                                         \
//         Tuple()                                     \
//         {                                           \
//                                                     \
//         }                                           \
//                                                     \
//         template <typename T>                       \
//         Tuple(const T &that)                        \
//             : XL_TUPLE_INITIALIZE_LIST_COPY(n)      \
//         {                                           \
//                                                     \
//         }                                           \
//                                                     \
//         Tuple(XL_TUPLE_TYPENAME_VARIABLE(n))        \
//             : XL_TUPLE_INITIALIZE_LIST(n)           \
//         {                                           \
//                                                     \
//         }                                           \
//                                                     \
//         template <typename T>                       \
//         Tuple &operator = (const T &that)           \
//         {                                           \
//             XL_STATIC_ASSERT(Size <= T::Size);      \
//             XL_TUPLE_ASSIGN(n)                      \
//                                                     \
//             return *this;                           \
//         }                                           \
//                                                     \
//         Tuple &operator = (const Tuple &that)       \
//         {                                           \
//             if (this != &that)                      \
//             {                                       \
//                 XL_TUPLE_ASSIGN(n)                  \
//             }                                       \
//                                                     \
//             return *this;                           \
//         }                                           \
//                                                     \
//     public:                                         \
//         static const size_t Size = n;               \
//                                                     \
//     public:                                         \
//         template <typename T>                       \
//         bool operator == (const T &that) const      \
//         {                                           \
//             XL_STATIC_ASSERT(Size == T::Size);      \
//             return XL_TUPLE_EQUAL(n);               \
//         }                                           \
//                                                     \
//         template <typename T>                       \
//         bool operator != (const T &that) const      \
//         {                                           \
//             XL_STATIC_ASSERT(Size == T::Size);      \
//             return XL_TUPLE_NOT_EQUAL(n);           \
//         }                                           \
//                                                     \
//         template <typename T>                       \
//         bool operator < (const T &that) const       \
//         {                                           \
//             XL_STATIC_ASSERT(Size == T::Size);      \
//             XL_TUPLE_LITTER(n)                      \
//             return false;                           \
//         }                                           \
//                                                     \
//         template <typename T>                       \
//         bool operator > (const T &that) const       \
//         {                                           \
//             XL_STATIC_ASSERT(Size == T::Size);      \
//             XL_TUPLE_GREATER(n)                     \
//             return false;                           \
//         }                                           \
//                                                     \
//         template <typename T>                       \
//         bool operator <= (const T &that) const      \
//         {                                           \
//             XL_STATIC_ASSERT(Size == T::Size);      \
//             XL_TUPLE_LITTER(n)                      \
//             return true;                            \
//         }                                           \
//                                                     \
//         template <typename T>                       \
//         bool operator >= (const T &that) const      \
//         {                                           \
//             XL_STATIC_ASSERT(Size == T::Size);      \
//             XL_TUPLE_GREATER(n)                     \
//             return true;                            \
//         }                                           \
//     };                                              \
// 
// #define XL_TUPLE_IMPLEMENT(n)    XL_REPY(XL_TUPLE_IMPLEMENT_PATTERN, n, XL_NIL)
// 
// XL_TUPLE_IMPLEMENT(XL_TUPLE_DEFINE_MAX)

    template <size_t Index, typename... T>
    class TupleImpl;

    template <typename... T>
    struct Tuple;

    template <typename... T>
    struct Tuple : public TupleImpl<0, T...>
    {
        static const size_t Size = sizeof...(T);

        Tuple() : TupleImpl<0, T...>()
        {

        }

        Tuple(T... t) : TupleImpl<0, T...>(t...)
        {

        }

        template <typename... U>
        Tuple(const Tuple<U...> &that) : TupleImpl<0, T...>(that)
        {

        }
    };

    template <size_t Index>
    class TupleImpl<Index>
    {
    public:
        template <typename... U>
        TupleImpl()
        {

        }

        template <typename... U>
        TupleImpl(const Tuple<U...> &that)
        {

        }

        template <typename... U>
        bool operator == (const Tuple<U...> &that) const
        {
            return true;
        }

        template <typename... U>
        bool operator != (const Tuple<U...> &that) const
        {
            return false;
        }

        template <typename... U>
        bool operator < (const Tuple<U...> &that) const
        {
            return false;
        }

        template <typename... U>
        bool operator > (const Tuple<U...> &that) const
        {
            return false;
        }

        template <typename... U>
        bool operator <= (const Tuple<U...> &that) const
        {
            return false;
        }

        template <typename... U>
        bool operator >= (const Tuple<U...> &that) const
        {
            return false;
        }

        template <typename U>
        TupleImpl &operator += (U delta)
        {
            return *this;
        }

        template <typename U>
        TupleImpl &operator -= (U delta)
        {
            return *this;
        }

        template <typename U>
        TupleImpl &operator *= (U factor)
        {
            return *this;
        }

        template <typename U>
        TupleImpl &operator /= (U factor)
        {
            return *this;
        }

        template <typename U>
        TupleImpl &operator %= (U factor)
        {
            return *this;
        }

        template <typename... U>
        TupleImpl &operator += (const Tuple<U...> &that)
        {
            return *this;
        }

        template <typename... U>
        TupleImpl &operator -= (const Tuple<U...> &that)
        {
            return *this;
        }

        template <int N>
        const int &&At() const
        {
            return 0;
        }
    };

    template <size_t Index, typename Ti, typename... T>
    class TupleImpl<Index, Ti, T...> : public TupleImpl<Index + 1, T...>
    {
    public:
        TupleImpl() : m_tValue(), TupleImpl<Index + 1, T...>()
        {

        }

        TupleImpl(Ti ti, T... t) : m_tValue(ti), TupleImpl<Index + 1, T...>(t...)
        {

        }

        template <typename... U>
        TupleImpl(const Tuple<U...> &that) : m_tValue(that.At<Index>()), TupleImpl<Index + 1, T...>(that)
        {

        }

        template <typename... U>
        bool operator == (const Tuple<U...> &that) const
        {
            if (!(m_tValue == that.At<Index>()))
            {
                return false;
            }

            return TupleImpl<Index + 1, T...>::operator == (that);
        }

        template <typename... U>
        bool operator != (const Tuple<U...> &that) const
        {
            if (m_tValue != that.At<Index>())
            {
                return true;
            }

            return TupleImpl<Index + 1, T...>::operator != (that);
        }

        template <typename... U>
        bool operator < (const Tuple<U...> &that) const
        {
            if (m_tValue < that.At<Index>())
            {
                return true;
            }

            return TupleImpl<Index + 1, T...>::operator < (that);
        }

        template <typename... U>
        bool operator > (const Tuple<U...> &that) const
        {
            if (m_tValue > that.At<Index>())
            {
                return true;
            }

            return TupleImpl<Index + 1, T...>::operator > (that);
        }

        template <typename... U>
        bool operator <= (const Tuple<U...> &that) const
        {
            if (m_tValue <= that.At<Index>())
            {
                return true;
            }

            return TupleImpl<Index + 1, T...>::operator <= (that);
        }

        template <typename... U>
        bool operator >= (const Tuple<U...> &that) const
        {
            if (m_tValue >= that.At<Index>())
            {
                return true;
            }

            return TupleImpl<Index + 1, T...>::operator >= (that);
        }

        template <typename U>
        TupleImpl &operator += (U delta)
        {
            m_tValue = (Ti)(m_tValue + delta);
            TupleImpl<Index + 1, T...>::operator += (delta);
            return *this;
        }

        template <typename U>
        TupleImpl &operator -= (U delta)
        {
            m_tValue = (Ti)(m_tValue - delta);
            TupleImpl<Index + 1, T...>::operator -= (delta);
            return *this;
        }

        template <typename U>
        TupleImpl &operator *= (U factor)
        {
            m_tValue = (Ti)(m_tValue * factor);
            TupleImpl<Index + 1, T...>::operator *= (factor);
            return *this;
        }

        template <typename U>
        TupleImpl &operator /= (U factor)
        {
            m_tValue = (Ti)(m_tValue / factor);
            TupleImpl<Index + 1, T...>::operator /= (factor);
            return *this;
        }

        template <typename U>
        TupleImpl &operator %= (U factor)
        {
            m_tValue = (Ti)(m_tValue % factor);
            TupleImpl<Index + 1, T...>::operator %= (factor);
            return *this;
        }

        template <typename... U>
        TupleImpl &operator = (const Tuple<U...> &that)
        {
            m_tValue = (Ti)that.At<Index>();
            TupleImpl<Index + 1, T...>::operator = (that);
            return *this;
        }

        template <typename... U>
        TupleImpl &operator += (const Tuple<U...> &that)
        {
            m_tValue = (Ti)(m_tValue + that.At<Index>());
            TupleImpl<Index + 1, T...>::operator += (that);
            return *this;
        }

        template <typename... U>
        TupleImpl &operator -= (const Tuple<U...> &that)
        {
            m_tValue = (Ti)(m_tValue - that.At<Index>());
            TupleImpl<Index + 1, T...>::operator += (that);
            return *this;
        }

        template <int N>
        Ti &At()
        {
            return TupleImpl<Index + 1, T...>::At<N>();
        }

        template <int N>
        const Ti &At() const
        {
            return TupleImpl<Index + 1, T...>::At<N>();
        }

        template <>
        Ti &At<Index>()
        {
            return m_tValue;
        }

        template <>
        const Ti &At<Index>() const
        {
            return m_tValue;
        }

    protected:
        Ti m_tValue;
    };

} // namespace xl


#endif // #ifndef __XLTUPLE_H_4720D247_760A_43F2_9611_6673153C5C68_INCLUDED__

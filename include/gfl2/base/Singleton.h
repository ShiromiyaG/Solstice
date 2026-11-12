#ifndef GFL2_BASE_SINGLETON_H
#define GFL2_BASE_SINGLETON_H

// gfl2::base::SingletonAccessor<T>::GetInstance(): exported for many T by the executable
// (static.crs, signatures.csv). static: its code reads no argument. it returns the instance
// (T *), a guess from how callers use the result.
namespace gfl2 {
namespace base {

template <class T>
class SingletonAccessor {
public:
    static T *GetInstance();
};

}  // namespace base
}  // namespace gfl2

#endif

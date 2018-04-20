namespace JFC
{
//! \brief Design patterns and idioms
namespace Patterns
{

//! \brief NonCopyable idiom.
//!
//! prefer boost::nocopyable, but if you are using this
//! library, boost is not an option.
//!
//! Usage:
//! \code
//! class CantCopy : private NonCopyable <CantCopy>
//! {};
//! \endcode
//! \see https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-copyable_Mixin
template <class T>
class NonCopyable
{
protected:
    NonCopyable () {}
    ~NonCopyable () {} /// Protected non-virtual destructor
private:
    NonCopyable (const NonCopyable &);
    NonCopyable & operator = (const NonCopyable &);
};

}
}

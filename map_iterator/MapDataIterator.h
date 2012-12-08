#ifndef map_data_iterator_adapter_h
#define map_data_iterator_adapter_h 1

#include <iterator>

template <class BiDirIter>
class map_data_iterator_adapter
  : public std::iterator<std::bidirectional_iterator_tag, typename BiDirIter::value_type::second_type> 
{
  public:
      typedef typename BiDirIter::value_type::second_type IteratorContentType;

      explicit map_data_iterator_adapter(BiDirIter const & iter = BiDirIter())
      : m_iter(iter)
      {
      }

      bool operator==(map_data_iterator_adapter const & rhs) const
      {
          return (m_iter == rhs.m_iter);
      }

      bool operator!=(map_data_iterator_adapter const & rhs) const
      {
          return !(*this == rhs);
      }

      const IteratorContentType& operator*()
      {
          return m_iter->second;
      }

      const IteratorContentType& operator*() const
      {
          return m_iter->second;
      }

      const IteratorContentType* operator->() const
      {
          return &(m_iter->second);
      }

      map_data_iterator_adapter& operator++()
      {
          ++m_iter;
          return *this;
      }

      const map_data_iterator_adapter operator++(int)
      {
          map_data_iterator_adapter temp(m_iter);
          ++m_iter;
          return temp;
      }

      map_data_iterator_adapter& operator--()
      {
          --m_iter;
          return *this;
      }

      const map_data_iterator_adapter operator--(int)
      {
          map_data_iterator_adapter temp(m_iter);
          --m_iter;
          return temp;
      }
    
  private:
    BiDirIter m_iter;
};

// a helper function to save some typing of tedious nested C++ types
// similar to std::make_pair function
template <class BiDirIter>
map_data_iterator_adapter<BiDirIter> make_map_data_iterator_adaptor(BiDirIter const& iter)
{
    return map_data_iterator_adapter<BiDirIter>(iter);
}

#endif

// Generated by gencpp from file rosserial_msgs/RequestParamResponse.msg
// DO NOT EDIT!


#ifndef ROSSERIAL_MSGS_MESSAGE_REQUESTPARAMRESPONSE_H
#define ROSSERIAL_MSGS_MESSAGE_REQUESTPARAMRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rosserial_msgs
{
template <class ContainerAllocator>
struct RequestParamResponse_
{
  typedef RequestParamResponse_<ContainerAllocator> Type;

  RequestParamResponse_()
    : ints()
    , floats()
    , strings()  {
    }
  RequestParamResponse_(const ContainerAllocator& _alloc)
    : ints(_alloc)
    , floats(_alloc)
    , strings(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _ints_type;
  _ints_type ints;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _floats_type;
  _floats_type floats;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _strings_type;
  _strings_type strings;





  typedef boost::shared_ptr< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> const> ConstPtr;

}; // struct RequestParamResponse_

typedef ::rosserial_msgs::RequestParamResponse_<std::allocator<void> > RequestParamResponse;

typedef boost::shared_ptr< ::rosserial_msgs::RequestParamResponse > RequestParamResponsePtr;
typedef boost::shared_ptr< ::rosserial_msgs::RequestParamResponse const> RequestParamResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rosserial_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'rosserial_msgs': ['/home/ubuntu/catkin_ws/src/rosserial_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9f0e98bda65981986ddf53afa7a40e49";
  }

  static const char* value(const ::rosserial_msgs::RequestParamResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9f0e98bda6598198ULL;
  static const uint64_t static_value2 = 0x6ddf53afa7a40e49ULL;
};

template<class ContainerAllocator>
struct DataType< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosserial_msgs/RequestParamResponse";
  }

  static const char* value(const ::rosserial_msgs::RequestParamResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
int32[]   ints\n\
float32[] floats\n\
string[]  strings\n\
\n\
";
  }

  static const char* value(const ::rosserial_msgs::RequestParamResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ints);
      stream.next(m.floats);
      stream.next(m.strings);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RequestParamResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosserial_msgs::RequestParamResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosserial_msgs::RequestParamResponse_<ContainerAllocator>& v)
  {
    s << indent << "ints[]" << std::endl;
    for (size_t i = 0; i < v.ints.size(); ++i)
    {
      s << indent << "  ints[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.ints[i]);
    }
    s << indent << "floats[]" << std::endl;
    for (size_t i = 0; i < v.floats.size(); ++i)
    {
      s << indent << "  floats[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.floats[i]);
    }
    s << indent << "strings[]" << std::endl;
    for (size_t i = 0; i < v.strings.size(); ++i)
    {
      s << indent << "  strings[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.strings[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSSERIAL_MSGS_MESSAGE_REQUESTPARAMRESPONSE_H

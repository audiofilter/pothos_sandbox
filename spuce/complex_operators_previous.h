#pragma once
// forward declarations
#include "mixed_type.h"
//----------------------T1 + T2 operators----------------------------------
//!
template <typename T1, typename T2> inline bool operator ==(std::complex<T1> r, std::complex<T2> l)
{
  return ((real(r) == real(l)) && (imag(r) == imag(l)));  
}

///!
template <typename T1, typename T2> inline bool operator <=(std::complex<T1> r, std::complex<T2> l)
{
  return ((real(r) <= real(l)) && (imag(r) <= imag(l)));  
}
///!

template <typename T1, typename T2> inline bool operator <(std::complex<T1> r, std::complex<T2> l){
  return ((real(r) < real(l)) && (imag(r) < imag(l)));  
}
///!
template <typename T1, typename T2> inline bool operator >=(std::complex<T1> r, std::complex<T2> l)
{
  return ((real(r) >= real(l)) && (imag(r) >= imag(l)));  
}
///!
template <typename T1, typename T2> inline bool operator >(std::complex<T1> r, std::complex<T2> l)
{
  return ((real(r) > real(l)) && (imag(r) > imag(l)));  
}

//!
template <typename T1, typename T2> inline bool operator !=(std::complex<T1> r, std::complex<T2> l)
{
  return ((real(r) != real(l)) || (imag(r) != imag(l)));  
}
// Combination operators, order is important because inline
/*
don't repeate these ones.....
*/
#define COMPLEX_SINGOP( T1, T2, RESULT) \
	std::complex<RESULT> inline operator -(std::complex<T1> r, std::complex<T2> l) { \
		return std::complex<RESULT>((RESULT)std::real(r)-(RESULT)std::real(l),(RESULT)std::imag(r)-(RESULT)std::imag(l)); } \
	std::complex<RESULT> inline operator -(T1 r, std::complex<T2> l) {		\
		return std::complex<RESULT>(((RESULT)r-(RESULT)std::real(l)),-(RESULT)std::imag(l)); } \
	std::complex<RESULT> inline operator -(std::complex<T1> l, T2 r) {		\
		return std::complex<RESULT>(((RESULT)r-(RESULT)std::real(l)),-(RESULT)std::imag(l)); } \
																																				\
	std::complex<RESULT> inline operator +(std::complex<T1> r, std::complex<T2> l) { \
		return std::complex<RESULT>((RESULT)std::real(r)+(RESULT)std::real(l),(RESULT)std::imag(r)+(RESULT)std::imag(l)); } \
	std::complex<RESULT> inline operator +(T1 r, std::complex<T2> l) {		\
		return(std::complex<RESULT>((RESULT)r+(RESULT)std::real(l),(RESULT)std::imag(l))); } \
	std::complex<RESULT> inline operator +(std::complex<T1> l, T2 r) {		\
		return(std::complex<RESULT>((RESULT)r+(RESULT)std::real(l),(RESULT)std::imag(l))); } \
																																				\
	std::complex<RESULT> inline operator *(T1 r, std::complex<T2> l) {		\
		return(std::complex<RESULT>(r*std::real(l),r*std::imag(l))); }											\
	std::complex<RESULT> inline operator *(std::complex<T1> l, T2 r) {		\
		return(std::complex<RESULT>(r*std::real(l),r*std::imag(l))); }											\
	std::complex<RESULT> inline operator *(std::complex<T1> r, std::complex<T2> l) { \
	 return(std::complex<RESULT>(((std::real(r)*std::real(l)) - (std::imag(r)*std::imag(l))),							\
															 (std::real(r)*std::imag(l) + std::imag(r)*std::real(l)))); }							\
																																				\
	std::complex<RESULT> inline operator /(std::complex<T1> l, T2 r) {		\
		return(std::complex<RESULT>((RESULT)std::real(l)/(RESULT)r,(RESULT)std::imag(l)/(RESULT)r)); } \
	std::complex<RESULT> inline operator /(std::complex<T1> r, std::complex<T2> l) { \
		return (std::complex<RESULT>((r * conj(l))/((RESULT)norm(l)))); }	\
	std::complex<RESULT> inline operator /(T1 r, std::complex<T2> l) {		\
		return(std::complex<RESULT>((r*conj(l))/(RESULT)norm(l))); } 

COMPLEX_SINGOP(float,float,float)
COMPLEX_SINGOP(double,double,double)
COMPLEX_SINGOP(int64_t,int64_t,int64_t)
COMPLEX_SINGOP(int32_t,int32_t,int32_t)
COMPLEX_SINGOP(int16_t,int16_t,int16_t)
COMPLEX_SINGOP(int8_t,int8_t,int8_t)

#define COMPLEX_MULTOP( T1, T2, RESULT) \
  COMPLEX_SINGOP(T1,T2,RESULT) \
  COMPLEX_SINGOP(T2,T1,RESULT) 

// Explicit spuce::mixed cases (May need to add more)

COMPLEX_MULTOP(float,int64_t,float)
COMPLEX_MULTOP(float,int32_t,float)
COMPLEX_MULTOP(float,int16_t,float)
COMPLEX_MULTOP(float,int8_t,float)
COMPLEX_MULTOP(int64_t,int32_t,int64_t)
COMPLEX_MULTOP(int64_t,int16_t,int64_t)
COMPLEX_MULTOP(int64_t,int8_t,int64_t)

COMPLEX_MULTOP(int32_t,int16_t,int32_t)
COMPLEX_MULTOP(int32_t,int8_t,int32_t)

COMPLEX_MULTOP(int16_t,int8_t,int16_t)

COMPLEX_MULTOP(double,int64_t,double)
COMPLEX_MULTOP(double,int32_t,double)
COMPLEX_MULTOP(double,int16_t,double)
COMPLEX_MULTOP(double,int8_t,double)
COMPLEX_MULTOP(double,float,double)
/*
template <typename T1, typename T2> std::complex<typename spuce::mixed_type<T1,T2>::dtype> operator *(T1 r, std::complex<T2> l) {
  return(std::complex<typename spuce::mixed_type<T1,T2>::dtype>(r*std::real(l),r*std::imag(l)));
}
template <typename T1, typename T2> std::complex<typename spuce::mixed_type<T1,T2>::dtype> operator +(T1 r, std::complex<T2> l) {
	return(std::complex<typename spuce::mixed_type<T1,T2>::dtype>((typename spuce::mixed_type<T1,T2>::dtype)r+(typename spuce::mixed_type<T1,T2>::dtype)std::real(l),
																																(typename spuce::mixed_type<T1,T2>::dtype)std::imag(l)
											 ));
}
template <typename T1, typename T2> std::complex<typename spuce::mixed_type<T1,T2>::dtype> operator /(T1 r, std::complex<T2> l) {
	return(std::complex<typename spuce::mixed_type<T1,T2>::dtype>((r*conj(l)/(typename spuce::mixed_type<T1,T2>::dtype)norm(l))));
}
*/

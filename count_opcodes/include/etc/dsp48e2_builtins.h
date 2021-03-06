// This header file is generated by script. Don't modify it manully

#ifndef _DSP48E2_BUILTINS_H_
#define _DSP48E2_BUILTINS_H_

// Flags 
#define DSP_REGISTER_DEFAULT 0x00000000
#define DSP_REGISTER_A1 0x00000001
#define DSP_REGISTER_A2 0x00000002
#define DSP_REGISTER_B1 0x00000004
#define DSP_REGISTER_B2 0x00000008
#define DSP_REGISTER_D 0x00000010
#define DSP_REGISTER_AD 0x00000020
#define DSP_REGISTER_M 0x00000040
#define DSP_REGISTER_C 0x00000080
#define DSP_REGISTER_P 0x00000100
#define DSP_REGISTER_NO 0x00000200

// DSP builtin wrapper functions

dsp48_t
__builtin_mac_add(
    int64_t flags,
    dsp27_t a,
    dsp18_t b,
    dsp48_t c) __attribute__((always_inline));

dsp48_t
__builtin_mac_sub(
    int64_t flags,
    dsp25_t a,
    dsp18_t b,
    dsp48_t c) __attribute__((always_inline));

dsp48_t
__builtin_mac_subed(
    int64_t flags,
    dsp25_t a,
    dsp18_t b,
    dsp48_t c) __attribute__((always_inline));


#ifdef __HLS_SYN__
// DSP state type
typedef dsp48_t __xilinx_dsp_state;
#ifdef __cplusplus
extern "C" {
#endif
int64_t __attribute__((bitwidth(48)))
_ssdm_op_DSP( 
    __xilinx_dsp_state *state, // Pass nullptr if we do not do accumulation 
    int32_t func_index,
    int64_t flags,
    int32_t __attribute__((bitwidth(27))) d,
    int32_t __attribute__((bitwidth(30))) a,
    int32_t __attribute__((bitwidth(18))) b,
    int64_t __attribute__((bitwidth(48))) c,
    int32_t __attribute__((bitwidth(1))) carryin,
    int32_t __attribute__((bitwidth(1))) *carryout);

int64_t __attribute__((bitwidth(48)))
_ssdm_op_DSP_AB( 
    __xilinx_dsp_state *state, // Pass nullptr if we do not do accumulation 
    int32_t func_index,
    int64_t flags,
    int64_t __attribute__((bitwidth(48))) ab,
    int64_t __attribute__((bitwidth(48))) c,
    int32_t __attribute__((bitwidth(1))) carryin,
    int32_t __attribute__((bitwidth(1))) *carryout);

#ifdef __cplusplus
}
#endif
#endif
dsp48_t
__builtin_mac_add(
    int64_t flags,
    dsp27_t a,
    dsp18_t b,
    dsp48_t c)
{
#ifndef __HLS_SYN__
  return ((dsp48_t)a) * ((dsp48_t)b) + c;
#else
  return (int64_t)_ssdm_op_DSP(0, 0, flags, 0, a, b, c, 0, 0);
#endif
}

dsp48_t
__builtin_mac_sub(
    int64_t flags,
    dsp25_t a,
    dsp18_t b,
    dsp48_t c)
{
#ifndef __HLS_SYN__
  return ((dsp48_t)a) * ((dsp48_t)b) - c;
#else
  return (int64_t)_ssdm_op_DSP(0, 1, flags, 0, a, b, c, 0, 0);
#endif
}

dsp48_t
__builtin_mac_subed(
    int64_t flags,
    dsp25_t a,
    dsp18_t b,
    dsp48_t c)
{
#ifndef __HLS_SYN__
  return c - ((dsp48_t)a) * ((dsp48_t)b);
#else
  return (int64_t)_ssdm_op_DSP(0, 2, flags, 0, a, b, c, 0, 0);
#endif
}

#endif

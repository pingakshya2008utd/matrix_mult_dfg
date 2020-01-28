#ifndef X_DSP_DP_BUILTINS_H
#define X_DSP_DP_BUILTINS_H

// User interfaces.
int32_t __builtin_mac16x2(
    int16_t A1in,
    int16_t A2in,
    int16_t B1in,
    int16_t B2in,
    int32_t Accum,
    dsp1_t clockx2,
    dsp1_t toggle,
    dsp1_t clear) __attribute__((always_inline));

dsp48_t __builtin_mac8x2(
    int16_t A1in,
    int16_t A2in,
    int16_t B1in,
    int16_t B2in,
    dsp48_t Accum,
    dsp1_t clockx2,
    dsp1_t toggle,
    dsp1_t clear) __attribute__((always_inline));

// HLS Internal functions, don't use them directly.
#ifdef __HLS_SYN__
#ifdef __cplusplus
extern "C" {
#endif
int32_t _ssdm_op_DSP16x2_Mac(
    int16_t A1in,
    int16_t A2in,
    int16_t B1in,
    int16_t B2in,
    int32_t Accum,
    int __attribute__((bitwidth(1))) clockx2,
    int __attribute__((bitwidth(1))) toggle,
    int __attribute__((bitwidth(1))) clear);

int64_t __attribute__((bitwidth(48))) 
_ssdm_op_DSP8x2_Mac(
    int16_t A1in,
    int16_t A2in,
    int16_t B1in,
    int16_t B2in,
    int64_t __attribute__((bitwidth(48))) Accum,
    int __attribute__((bitwidth(1))) clockx2,
    int __attribute__((bitwidth(1))) toggle,
    int __attribute__((bitwidth(1))) clear);

#ifdef __cplusplus
}
#endif
#endif

int32_t __builtin_mac16x2(
    int16_t A1in,
    int16_t A2in,
    int16_t B1in,
    int16_t B2in,
    int32_t Accum,
    dsp1_t clockx2,
    dsp1_t toggle,
    dsp1_t clear) {
#ifdef __HLS_SYN__
  return _ssdm_op_DSP16x2_Mac(A1in, A2in, B1in, B2in, Accum, clockx2, toggle, clear);
#else
  return A1in * B1in + A2in * B2in + (clear ? 0 : Accum);
#endif
}

dsp48_t __builtin_mac8x2(
    int16_t A1in,
    int16_t A2in,
    int16_t B1in,
    int16_t B2in,
    dsp48_t Accum,
    dsp1_t clockx2,
    dsp1_t toggle,
    dsp1_t clear) {
#ifdef __HLS_SYN__
  return (long long)_ssdm_op_DSP8x2_Mac(A1in, A2in, B1in, B2in, Accum, clockx2, toggle, clear);
#else
  int8_t A1inL = (int8_t)A1in;
  int8_t A2inL = (int8_t)A2in;
  int8_t B1inL = (int8_t)B1in;
  int8_t B2inL = (int8_t)B2in;
  int8_t A1inH = (int8_t)(A1in >> 8);
  int8_t A2inH = (int8_t)(A2in >> 8);
  int8_t B1inH = (int8_t)(B1in >> 8);
  int8_t B2inH = (int8_t)(B2in >> 8);
  int64_t AccumX = (int64_t)Accum;
  int32_t AccumL = (int32_t)((AccumX << 40) >> 40);
  int32_t AccumH = (int32_t)((AccumX >> 24) & 0xFFFFFF);
  int32_t ResultL = A1inL * B1inL + A2inL * B2inL + (clear ? 0 : AccumL);
  int32_t ResultH = A1inH * B1inH + A2inH * B2inH + (clear ? 0 : AccumH);
  int64_t Result = (ResultH << 24) & 0xFFFFFF000000 & (ResultL & 0xFFFFFF);
  return Result;
#endif
}

#endif


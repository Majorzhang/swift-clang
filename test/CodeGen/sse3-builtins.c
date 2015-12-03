// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +sse3 -emit-llvm -o - -Werror | FileCheck %s

// Don't include mm_malloc.h, it's system specific.
#define __MM_MALLOC_H

#include <x86intrin.h>

__m128d test_mm_addsub_pd(__m128d A, __m128d B) {
  // CHECK-LABEL: test_mm_addsub_pd
  // CHECK: call <2 x double> @llvm.x86.sse3.addsub.pd
  return _mm_addsub_pd(A, B);
}

__m128 test_mm_addsub_ps(__m128 A, __m128 B) {
  // CHECK-LABEL: test_mm_addsub_ps
  // CHECK: call <4 x float> @llvm.x86.sse3.addsub.ps
  return _mm_addsub_ps(A, B);
}

__m128d test_mm_hadd_pd(__m128d A, __m128d B) {
  // CHECK-LABEL: test_mm_hadd_pd
  // CHECK: call <2 x double> @llvm.x86.sse3.hadd.pd
  return _mm_hadd_pd(A, B);
}

__m128 test_mm_hadd_ps(__m128 A, __m128 B) {
  // CHECK-LABEL: test_mm_hadd_ps
  // CHECK: call <4 x float> @llvm.x86.sse3.hadd.ps
  return _mm_hadd_ps(A, B);
}

__m128d test_mm_hsub_pd(__m128d A, __m128d B) {
  // CHECK-LABEL: test_mm_hsub_pd
  // CHECK: call <2 x double> @llvm.x86.sse3.hsub.pd
  return _mm_hsub_pd(A, B);
}

__m128 test_mm_hsub_ps(__m128 A, __m128 B) {
  // CHECK-LABEL: test_mm_hsub_ps
  // CHECK: call <4 x float> @llvm.x86.sse3.hsub.ps
  return _mm_hsub_ps(A, B);
}

__m128i test_mm_lddqu_si128(__m128i const* P) {
  // CHECK-LABEL: test_mm_lddqu_si128
  // CHECK: call <16 x i8> @llvm.x86.sse3.ldu.dq
  return _mm_lddqu_si128(P);
}

__m128d test_mm_loaddup_pd(double const* P) {
  // CHECK-LABEL: test_mm_loaddup_pd
  // CHECK: load double*
  return _mm_loaddup_pd(P);
}

__m128d test_mm_movedup_pd(__m128d A) {
  // CHECK-LABEL: test_mm_movedup_pd
  // CHECK: shufflevector <2 x double> %{{.*}}, <2 x double> %{{.*}}, <2 x i32> zeroinitializer
  return _mm_movedup_pd(A);
}

__m128 test_mm_movehdup_ps(__m128 A) {
  // CHECK-LABEL: test_mm_movehdup_ps
  // CHECK: shufflevector <4 x float> %{{.*}}, <4 x float> %{{.*}}, <4 x i32> <i32 1, i32 1, i32 3, i32 3>
  return _mm_movehdup_ps(A);
}

__m128 test_mm_movedup_ps(__m128 A) {
  // CHECK-LABEL: test_mm_movedup_ps
  // CHECK: shufflevector <4 x float> %{{.*}}, <4 x float> %{{.*}}, <4 x i32> <i32 0, i32 0, i32 2, i32 2>
  return _mm_moveldup_ps(A);
}

/*
 * heli_q8_oppgave3_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_oppgave3".
 *
 * Model version              : 11.17
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Oct 12 14:04:56 2021
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_stream),
  sizeof(t_stream_ptr),
  sizeof(intmax_t),
  sizeof(ptrdiff_t),
  sizeof(size_t),
  sizeof(t_int64),
  sizeof(t_uint64),
  sizeof(t_wide_char),
  sizeof(t_game_controller),
  sizeof(t_card),
  sizeof(t_task)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_stream",
  "t_stream_ptr",
  "intmax_t",
  "ptrdiff_t",
  "size_t",
  "t_int64",
  "t_uint64",
  "t_wide_char",
  "t_game_controller",
  "t_card",
  "t_task"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&heli_q8_oppgave3_B.PitchCounttorad), 0, 0, 46 },

  { (char_T *)(&heli_q8_oppgave3_B.StreamFormattedRead1_o2), 1, 0, 12 },

  { (char_T *)(&heli_q8_oppgave3_B.StreamFormattedRead1_o8), 6, 0, 2 },

  { (char_T *)(&heli_q8_oppgave3_B.StreamCall2_o2), 3, 0, 1 },

  { (char_T *)(&heli_q8_oppgave3_B.StreamFormattedRead1_o10), 8, 0, 9 }
  ,

  { (char_T *)(&heli_q8_oppgave3_DW.HILInitialize_AIMinimums[0]), 0, 0, 68 },

  { (char_T *)(&heli_q8_oppgave3_DW.StreamCall2_Stream), 14, 0, 1 },

  { (char_T *)(&heli_q8_oppgave3_DW.GameController_Controller), 22, 0, 1 },

  { (char_T *)(&heli_q8_oppgave3_DW.HILInitialize_Card), 23, 0, 1 },

  { (char_T *)(&heli_q8_oppgave3_DW.HILReadEncoderTimebase_Task), 24, 0, 1 },

  { (char_T *)(&heli_q8_oppgave3_DW.Anglesencodervseuler_PWORK.LoggedData[0]),
    11, 0, 63 },

  { (char_T *)(&heli_q8_oppgave3_DW.UnitDelay_DSTATE), 1, 0, 6 },

  { (char_T *)(&heli_q8_oppgave3_DW.HILInitialize_ClockModes[0]), 6, 0, 46 },

  { (char_T *)(&heli_q8_oppgave3_DW.HILInitialize_POSortedChans[0]), 7, 0, 8 },

  { (char_T *)(&heli_q8_oppgave3_DW.ToFile_IWORK.Count), 10, 0, 1 },

  { (char_T *)(&heli_q8_oppgave3_DW.Skiptonextline_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&heli_q8_oppgave3_DW.StreamCall2_State), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  17U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&heli_q8_oppgave3_P.A_aug[0]), 0, 0, 62 },

  { (char_T *)(&heli_q8_oppgave3_P.HILWriteAnalog_channels[0]), 7, 0, 2 },

  { (char_T *)(&heli_q8_oppgave3_P.HILInitialize_OOTerminate), 0, 0, 123 },

  { (char_T *)(&heli_q8_oppgave3_P.HILInitialize_CKChannels[0]), 6, 0, 12 },

  { (char_T *)(&heli_q8_oppgave3_P.UnitDelay_InitialCondition), 1, 0, 6 },

  { (char_T *)(&heli_q8_oppgave3_P.StreamFormattedRead_MaxUnits), 7, 0, 39 },

  { (char_T *)(&heli_q8_oppgave3_P.GameController_BufferSize), 5, 0, 1 },

  { (char_T *)(&heli_q8_oppgave3_P.HILInitialize_Active), 8, 0, 41 },

  { (char_T *)(&heli_q8_oppgave3_P.HILReadEncoderTimebase_Overflow), 3, 0, 259 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  9U,
  rtPTransitions
};

/* [EOF] heli_q8_oppgave3_dt.h */

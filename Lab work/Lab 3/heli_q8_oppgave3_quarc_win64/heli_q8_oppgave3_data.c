/*
 * heli_q8_oppgave3_data.c
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

#include "heli_q8_oppgave3.h"
#include "heli_q8_oppgave3_private.h"

/* Block parameters (default storage) */
P_heli_q8_oppgave3_T heli_q8_oppgave3_P = {
  /* Variable: A_aug
   * Referenced by: '<S7>/State-Space'
   */
  { 0.0, 0.0, 0.0, -1.0, -0.0, 1.0, 0.0, 0.0, -0.0, -0.0, 0.0, 0.0, 0.0, -0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: B_aug
   * Referenced by: '<S7>/State-Space'
   */
  { 0.0, 0.0, 1.606024179145487, 0.0, 0.0, 0.0, 9.3428571428571452, 0.0, 0.0,
    0.0 },

  /* Variable: C_aug
   * Referenced by: '<S7>/Gain1'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: F_aug
   * Referenced by:
   *   '<Root>/F'
   *   '<S7>/F1'
   */
  { 1.0475699325356413E-15, 6.8389843293326278, 28.593904259202478,
    2.7371693163945175E-16 },

  /* Variable: Joystick_gain_x
   * Referenced by: '<S15>/Joystick_gain_x'
   */
  1.0,

  /* Variable: Joystick_gain_y
   * Referenced by: '<S15>/Joystick_gain_y'
   */
  -1.0,

  /* Variable: K_aug
   * Referenced by:
   *   '<Root>/K'
   *   '<S7>/K1'
   */
  { 1.0475699325356413E-15, 6.8389843293326278, -1.8947246018194553E-15,
    3.3858533284285719, 28.593904259202478, 2.7371693163945175E-16,
    -1.4809271237516291E-15, -1.0000000000000004, -14.142135623730947,
    7.38719824283737E-16 },

  /* Variable: Vs_0
   * Referenced by: '<Root>/Constant'
   */
  6.0,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S4>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: -2*pi /4096
   * Referenced by: '<S4>/Pitch: Count to rad'
   */
  -0.0015339807878856412,

  /* Expression: 0
   * Referenced by: '<S5>/Constant4'
   */
  0.0,

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S5>/Gain1'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S5>/Gain2'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: -2 * pi /4096
   * Referenced by: '<S4>/Elevation: Count to rad'
   */
  -0.0015339807878856412,

  /* Computed Parameter: PitchTransferFcn_A
   * Referenced by: '<S4>/Pitch: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: PitchTransferFcn_C
   * Referenced by: '<S4>/Pitch: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: PitchTransferFcn_D
   * Referenced by: '<S4>/Pitch: Transfer Fcn'
   */
  50.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -10.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  10.0,

  /* Expression: 2*pi/8192
   * Referenced by: '<S4>/Travel: Count to rad'
   */
  0.00076699039394282058,

  /* Computed Parameter: TravelTransferFcn_A
   * Referenced by: '<S4>/Travel: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: TravelTransferFcn_C
   * Referenced by: '<S4>/Travel: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: TravelTransferFcn_D
   * Referenced by: '<S4>/Travel: Transfer Fcn'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 25
   * Referenced by: '<S6>/Step2'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step2'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S6>/Step2'
   */
  0.5,

  /* Expression: 35
   * Referenced by: '<S6>/Step3'
   */
  35.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step3'
   */
  0.0,

  /* Expression: -0.5
   * Referenced by: '<S6>/Step3'
   */
  -0.5,

  /* Expression: 40
   * Referenced by: '<S6>/Step4'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step4'
   */
  0.0,

  /* Expression: -0.7
   * Referenced by: '<S6>/Step4'
   */
  -0.7,

  /* Expression: 45
   * Referenced by: '<S6>/Step5'
   */
  45.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step5'
   */
  0.0,

  /* Expression: 0.7
   * Referenced by: '<S6>/Step5'
   */
  0.7,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S15>/Rate Transition: x'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S15>/Dead Zone: x'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S15>/Dead Zone: x'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S15>/Gain: x'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S6>/Switch'
   */
  0.0,

  /* Expression: eye(5)
   * Referenced by: '<S7>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S7>/State-Space'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S6>/Step'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S6>/Step'
   */
  0.1,

  /* Expression: 15
   * Referenced by: '<S6>/Step1'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step1'
   */
  0.0,

  /* Expression: -0.2
   * Referenced by: '<S6>/Step1'
   */
  -0.2,

  /* Expression: 20
   * Referenced by: '<S6>/Step6'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step6'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S6>/Step6'
   */
  0.1,

  /* Expression: 40
   * Referenced by: '<S6>/Step7'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step7'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S6>/Step7'
   */
  0.1,

  /* Expression: 45
   * Referenced by: '<S6>/Step8'
   */
  45.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step8'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S6>/Step8'
   */
  -0.1,

  /* Expression: 0
   * Referenced by: '<S15>/Rate Transition: y'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S15>/Dead Zone: y'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S15>/Dead Zone: y'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S15>/Gain: y'
   */
  1.1111111111111112,

  /* Expression: -1
   * Referenced by: '<S6>/Gain2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Switch1'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Back gain'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S1>/Front gain'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S7>/Integrator'
   */
  0.0,

  /* Computed Parameter: ElevationTransferFcn_A
   * Referenced by: '<S4>/Elevation: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: ElevationTransferFcn_C
   * Referenced by: '<S4>/Elevation: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: ElevationTransferFcn_D
   * Referenced by: '<S4>/Elevation: Transfer Fcn'
   */
  50.0,

  /* Expression: 5
   * Referenced by: '<S4>/Front motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S4>/Front motor: Saturation'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S4>/Back motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S4>/Back motor: Saturation'
   */
  -5.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: StreamCall2_SendBufferSize
   * Referenced by: '<S5>/Stream Call2'
   */
  8000,

  /* Computed Parameter: StreamCall2_ReceiveBufferSize
   * Referenced by: '<S5>/Stream Call2'
   */
  8000,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S8>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_o
   * Referenced by: '<S9>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_i
   * Referenced by: '<S10>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_g
   * Referenced by: '<S11>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_k
   * Referenced by: '<S12>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_kh
   * Referenced by: '<S13>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: StreamFormattedRead_MaxUnits
   * Referenced by: '<S14>/Stream Formatted Read'
   */
  80U,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: StreamFormattedRead1_MaxUnits
   * Referenced by: '<S5>/Stream Formatted Read1'
   */
  80U,

  /* Computed Parameter: GameController_BufferSize
   * Referenced by: '<S15>/Game Controller'
   */
  12U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  1,

  /* Computed Parameter: StreamCall2_NonBlocking
   * Referenced by: '<S5>/Stream Call2'
   */
  1,

  /* Computed Parameter: StreamCall2_Active
   * Referenced by: '<S5>/Stream Call2'
   */
  0,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S4>/HIL Write Analog'
   */
  0,

  /* Computed Parameter: GameController_AutoCenter
   * Referenced by: '<S15>/Game Controller'
   */
  0,

  /* Computed Parameter: GameController_Enabled
   * Referenced by: '<S15>/Game Controller'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S4>/HIL Read Encoder Timebase'
   */
  1U,

  /* Expression: value
   * Referenced by: '<S5>/String Constant1'
   */
  { 115U, 101U, 114U, 105U, 97U, 108U, 58U, 47U, 47U, 73U, 77U, 85U, 58U, 52U,
    63U, 98U, 97U, 117U, 100U, 61U, 49U, 49U, 53U, 50U, 48U, 48U, 44U, 119U,
    111U, 114U, 100U, 61U, 56U, 44U, 112U, 97U, 114U, 105U, 116U, 121U, 61U,
    110U, 111U, 110U, 101U, 44U, 115U, 116U, 111U, 112U, 61U, 49U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Expression: uri_argument
   * Referenced by: '<S5>/Stream Call2'
   */
  0U,

  /* Computed Parameter: StreamCall2_Endian
   * Referenced by: '<S5>/Stream Call2'
   */
  1U,

  /* Computed Parameter: GameController_ControllerNumber
   * Referenced by: '<S15>/Game Controller'
   */
  1U
};

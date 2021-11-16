/*
 * heli_q8_oppgave3.c
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
#include "heli_q8_oppgave3_dt.h"

t_stream heli_q8_oppgave3_rtZt_stream = NULL;

/* Block signals (default storage) */
B_heli_q8_oppgave3_T heli_q8_oppgave3_B;

/* Continuous states */
X_heli_q8_oppgave3_T heli_q8_oppgave3_X;

/* Block states (default storage) */
DW_heli_q8_oppgave3_T heli_q8_oppgave3_DW;

/* Real-time model */
static RT_MODEL_heli_q8_oppgave3_T heli_q8_oppgave3_M_;
RT_MODEL_heli_q8_oppgave3_T *const heli_q8_oppgave3_M = &heli_q8_oppgave3_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_oppgave3_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_oppgave3_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (heli_q8_oppgave3_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_oppgave3_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_oppgave3_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_oppgave3_M->Timing.perTaskSampleHits[5] =
      heli_q8_oppgave3_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_oppgave3_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_oppgave3_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_oppgave3_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 13;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_oppgave3_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_q8_oppgave3_output0(void)    /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall2_o1;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_TmpSignalConversionAtToFile[16];
  real_T rtb_BackmotorSaturation;
  real_T rtb_FrontmotorSaturation;
  int32_T rtb_StreamFormattedRead_o2;
  int32_T rtb_StreamCall2_o3;
  int32_T rtb_StreamFormattedRead1_o12;
  real_T tmp[9];
  real_T rtb_StateSpace[5];
  real_T rtb_StateSpace_0[5];
  real_T u_tmp[2];
  real_T az;
  real_T euler_rates_tmp;
  real_T euler_rates_tmp_0;
  real_T phi;
  real_T theta;
  int_T ci;
  int_T iy;
  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
    /* set solver stop time */
    if (!(heli_q8_oppgave3_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_oppgave3_M->solverInfo,
                            ((heli_q8_oppgave3_M->Timing.clockTickH0 + 1) *
        heli_q8_oppgave3_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_oppgave3_M->solverInfo,
                            ((heli_q8_oppgave3_M->Timing.clockTick0 + 1) *
        heli_q8_oppgave3_M->Timing.stepSize0 +
        heli_q8_oppgave3_M->Timing.clockTickH0 *
        heli_q8_oppgave3_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_oppgave3_M)) {
    heli_q8_oppgave3_M->Timing.t[0] = rtsiGetT(&heli_q8_oppgave3_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(heli_q8_oppgave3_DW.Skiptonextline_SubsysRanBC);
  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_oppgave3/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (heli_q8_oppgave3_DW.HILReadEncoderTimebase_Task, 1,
         &heli_q8_oppgave3_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_oppgave3_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_BackmotorSaturation =
          heli_q8_oppgave3_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_FrontmotorSaturation =
          heli_q8_oppgave3_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S4>/Pitch: Count to rad' */
    heli_q8_oppgave3_B.PitchCounttorad = heli_q8_oppgave3_P.PitchCounttorad_Gain
      * rtb_BackmotorSaturation;

    /* S-Function (stream_call_block): '<S5>/Stream Call2' incorporates:
     *  Constant: '<S5>/Constant4'
     *  S-Function (string_constant_block): '<S5>/String Constant1'
     */

    /* S-Function Block: heli_q8_oppgave3/IMU3/Stream Call2 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_oppgave3_P.Constant4_Value != 0);
      rtb_StreamCall2_o1 = NULL;
      switch (heli_q8_oppgave3_DW.StreamCall2_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_q8_oppgave3_P.StringConstant1_Value,
                              255) == 255) {
              rtmSetErrorStatus(heli_q8_oppgave3_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *)
                heli_q8_oppgave3_P.StringConstant1_Value,
                heli_q8_oppgave3_P.StreamCall2_NonBlocking != 0,
                heli_q8_oppgave3_P.StreamCall2_SendBufferSize,
                heli_q8_oppgave3_P.StreamCall2_ReceiveBufferSize,
                &heli_q8_oppgave3_DW.StreamCall2_Stream);
              if (result == 0) {
                heli_q8_oppgave3_DW.StreamCall2_State =
                  STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_oppgave3_DW.StreamCall2_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_oppgave3_P.StreamCall2_Endian);
                rtb_StreamCall2_o1 = &heli_q8_oppgave3_DW.StreamCall2_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_oppgave3_DW.StreamCall2_State =
                  STREAM_CALL_STATE_CONNECTING;
                result = 0;
              }
            }
          }
          break;
        }

       case STREAM_CALL_STATE_CONNECTING:
        {
          if (!close_flag) {
            const t_timeout timeout = { 0, 0, false };/* zero seconds */

            result = stream_poll(heli_q8_oppgave3_DW.StreamCall2_Stream,
                                 &timeout, STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_oppgave3_DW.StreamCall2_State =
                STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_oppgave3_DW.StreamCall2_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_oppgave3_P.StreamCall2_Endian);
              rtb_StreamCall2_o1 = &heli_q8_oppgave3_DW.StreamCall2_Stream;
              result = 0;
              break;
            } else if (result == 0) {
              break;
            }
          }

          /* Fall through deliberately */
        }

       case STREAM_CALL_STATE_CONNECTED:
        {
          rtb_StreamCall2_o1 = &heli_q8_oppgave3_DW.StreamCall2_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close
            (heli_q8_oppgave3_DW.StreamCall2_Stream);
          if (close_result == 0) {
            heli_q8_oppgave3_DW.StreamCall2_State =
              STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_oppgave3_DW.StreamCall2_Stream = NULL;
            rtb_StreamCall2_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_q8_oppgave3_B.StreamCall2_o2 = heli_q8_oppgave3_DW.StreamCall2_State;
      rtb_StreamCall2_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_read_block): '<S5>/Stream Formatted Read1' */
    {
      t_error result;
      heli_q8_oppgave3_B.StreamFormattedRead1_o9 = 0;
      heli_q8_oppgave3_B.StreamFormattedRead1_o11 = false;
      if (rtb_StreamCall2_o1 != NULL) {
        result = stream_scan_utf8_char_array(*rtb_StreamCall2_o1,
          heli_q8_oppgave3_P.StreamFormattedRead1_MaxUnits,
          &heli_q8_oppgave3_B.StreamFormattedRead1_o8, " :%f,%f,%f,%f,%f,%f\r"
          , &heli_q8_oppgave3_B.StreamFormattedRead1_o2
          , &heli_q8_oppgave3_B.StreamFormattedRead1_o3
          , &heli_q8_oppgave3_B.StreamFormattedRead1_o4
          , &heli_q8_oppgave3_B.StreamFormattedRead1_o5
          , &heli_q8_oppgave3_B.StreamFormattedRead1_o6
          , &heli_q8_oppgave3_B.StreamFormattedRead1_o7
          );
        heli_q8_oppgave3_B.StreamFormattedRead1_o11 = (result == 0);
        if (result > 0) {
          heli_q8_oppgave3_B.StreamFormattedRead1_o9 = result;
          result = 0;
        }
      } else {
        heli_q8_oppgave3_B.StreamFormattedRead1_o8 = 0;
        result = 0;
        heli_q8_oppgave3_B.StreamFormattedRead1_o2 = 0;
        heli_q8_oppgave3_B.StreamFormattedRead1_o3 = 0;
        heli_q8_oppgave3_B.StreamFormattedRead1_o4 = 0;
        heli_q8_oppgave3_B.StreamFormattedRead1_o5 = 0;
        heli_q8_oppgave3_B.StreamFormattedRead1_o6 = 0;
        heli_q8_oppgave3_B.StreamFormattedRead1_o7 = 0;
      }

      heli_q8_oppgave3_B.StreamFormattedRead1_o10 = (result ==
        -QERR_MISMATCHED_CHARACTER);
      if (result == -QERR_WOULD_BLOCK || result == -QERR_MISMATCHED_CHARACTER) {
        result = 0;
      }

      rtb_StreamFormattedRead1_o12 = result;
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion2' */
    heli_q8_oppgave3_B.DataTypeConversion2[0] =
      heli_q8_oppgave3_B.StreamFormattedRead1_o5;
    heli_q8_oppgave3_B.DataTypeConversion2[1] =
      heli_q8_oppgave3_B.StreamFormattedRead1_o6;
    heli_q8_oppgave3_B.DataTypeConversion2[2] =
      heli_q8_oppgave3_B.StreamFormattedRead1_o7;

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    heli_q8_oppgave3_B.DataTypeConversion1[0] =
      heli_q8_oppgave3_B.StreamFormattedRead1_o2;
    heli_q8_oppgave3_B.DataTypeConversion1[1] =
      heli_q8_oppgave3_B.StreamFormattedRead1_o3;
    heli_q8_oppgave3_B.DataTypeConversion1[2] =
      heli_q8_oppgave3_B.StreamFormattedRead1_o4;
    for (iy = 0; iy < 3; iy++) {
      /* Gain: '<S5>/Gain1' */
      heli_q8_oppgave3_B.Gain1[iy] = 0.0;

      /* Gain: '<S5>/Gain2' */
      heli_q8_oppgave3_B.Gain2[iy] = 0.0;

      /* Gain: '<S5>/Gain1' */
      heli_q8_oppgave3_B.Gain1[iy] += heli_q8_oppgave3_P.Gain1_Gain[iy] *
        heli_q8_oppgave3_B.DataTypeConversion2[0];

      /* Gain: '<S5>/Gain2' */
      heli_q8_oppgave3_B.Gain2[iy] += heli_q8_oppgave3_P.Gain2_Gain[iy] *
        heli_q8_oppgave3_B.DataTypeConversion1[0];

      /* Gain: '<S5>/Gain1' */
      heli_q8_oppgave3_B.Gain1[iy] += heli_q8_oppgave3_P.Gain1_Gain[iy + 3] *
        heli_q8_oppgave3_B.DataTypeConversion2[1];

      /* Gain: '<S5>/Gain2' */
      heli_q8_oppgave3_B.Gain2[iy] += heli_q8_oppgave3_P.Gain2_Gain[iy + 3] *
        heli_q8_oppgave3_B.DataTypeConversion1[1];

      /* Gain: '<S5>/Gain1' */
      heli_q8_oppgave3_B.Gain1[iy] += heli_q8_oppgave3_P.Gain1_Gain[iy + 6] *
        heli_q8_oppgave3_B.DataTypeConversion2[2];

      /* Gain: '<S5>/Gain2' */
      heli_q8_oppgave3_B.Gain2[iy] += heli_q8_oppgave3_P.Gain2_Gain[iy + 6] *
        heli_q8_oppgave3_B.DataTypeConversion1[2];
    }

    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
    /* MATLAB Function 'Gyro vector to [pitch rate, elevation rate, travle rate]': '<S3>:1' */
    /* '<S3>:1:4' */
    /* '<S3>:1:6' */
    /* '<S3>:1:7' */
    /* '<S3>:1:8' */
    az = heli_q8_oppgave3_B.Gain2[2];
    if (heli_q8_oppgave3_B.Gain2[2] == 0.0) {
      /* '<S3>:1:11' */
      /* '<S3>:1:12' */
      az = 1.0E-7;
    }

    /* '<S3>:1:16' */
    phi = atan(heli_q8_oppgave3_B.Gain2[1] / az);

    /* '<S3>:1:17' */
    theta = atan(heli_q8_oppgave3_B.Gain2[0] / sqrt(heli_q8_oppgave3_B.Gain2[1] *
      heli_q8_oppgave3_B.Gain2[1] + az * az));

    /* '<S3>:1:18' */
    heli_q8_oppgave3_B.euler_angles[0] = phi;
    heli_q8_oppgave3_B.euler_angles[1] = theta + 0.385;

    /* '<S3>:1:26' */
    /* '<S3>:1:33' */
    euler_rates_tmp = tan(theta);
    euler_rates_tmp_0 = sin(phi);
    phi = cos(phi);
    theta = cos(theta);
    tmp[0] = 1.0;
    tmp[3] = euler_rates_tmp_0 * euler_rates_tmp;
    tmp[6] = phi * euler_rates_tmp;
    tmp[1] = 0.0;
    tmp[4] = phi;
    tmp[7] = -euler_rates_tmp_0;
    tmp[2] = 0.0;
    tmp[5] = euler_rates_tmp_0 / theta;
    tmp[8] = phi / theta;
    for (iy = 0; iy < 3; iy++) {
      heli_q8_oppgave3_B.euler_rates[iy] = 0.0;
      heli_q8_oppgave3_B.euler_rates[iy] += tmp[iy] * heli_q8_oppgave3_B.Gain1[0];
      heli_q8_oppgave3_B.euler_rates[iy] += tmp[iy + 3] *
        heli_q8_oppgave3_B.Gain1[1];
      heli_q8_oppgave3_B.euler_rates[iy] += tmp[iy + 6] *
        heli_q8_oppgave3_B.Gain1[2];
    }

    if (az > 0.0) {
      /* '<S3>:1:34' */
      /* '<S3>:1:35' */
      heli_q8_oppgave3_B.euler_rates[1] = -heli_q8_oppgave3_B.euler_rates[1];

      /* '<S3>:1:36' */
      heli_q8_oppgave3_B.euler_rates[2] = -heli_q8_oppgave3_B.euler_rates[2];
    }

    /* End of MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' */

    /* Gain: '<S4>/Elevation: Count to rad' */
    heli_q8_oppgave3_B.ElevationCounttorad =
      heli_q8_oppgave3_P.ElevationCounttorad_Gain * rtb_FrontmotorSaturation;

    /* Gain: '<S4>/Travel: Count to rad' */
    heli_q8_oppgave3_B.TravelCounttorad =
      heli_q8_oppgave3_P.TravelCounttorad_Gain * rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  heli_q8_oppgave3_B.PitchTransferFcn = 0.0;
  heli_q8_oppgave3_B.PitchTransferFcn += heli_q8_oppgave3_P.PitchTransferFcn_C *
    heli_q8_oppgave3_X.PitchTransferFcn_CSTATE;
  heli_q8_oppgave3_B.PitchTransferFcn += heli_q8_oppgave3_P.PitchTransferFcn_D *
    heli_q8_oppgave3_B.PitchCounttorad;

  /* TransferFcn: '<Root>/Transfer Fcn' */
  heli_q8_oppgave3_B.TransferFcn = 0.0;
  heli_q8_oppgave3_B.TransferFcn += heli_q8_oppgave3_P.TransferFcn_C *
    heli_q8_oppgave3_X.TransferFcn_CSTATE;

  /* TransferFcn: '<S4>/Travel: Transfer Fcn' */
  heli_q8_oppgave3_B.TravelTransferFcn = 0.0;
  heli_q8_oppgave3_B.TravelTransferFcn += heli_q8_oppgave3_P.TravelTransferFcn_C
    * heli_q8_oppgave3_X.TravelTransferFcn_CSTATE;
  heli_q8_oppgave3_B.TravelTransferFcn += heli_q8_oppgave3_P.TravelTransferFcn_D
    * heli_q8_oppgave3_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
    /* UnitDelay: '<S8>/Unit Delay' */
    heli_q8_oppgave3_B.UnitDelay = heli_q8_oppgave3_DW.UnitDelay_DSTATE;

    /* RelationalOperator: '<S8>/Relational Operator' */
    heli_q8_oppgave3_B.RelationalOperator =
      (heli_q8_oppgave3_B.StreamFormattedRead1_o2 ==
       heli_q8_oppgave3_B.UnitDelay);

    /* UnitDelay: '<S9>/Unit Delay' */
    heli_q8_oppgave3_B.UnitDelay_g = heli_q8_oppgave3_DW.UnitDelay_DSTATE_p;

    /* RelationalOperator: '<S9>/Relational Operator' */
    heli_q8_oppgave3_B.RelationalOperator_m =
      (heli_q8_oppgave3_B.StreamFormattedRead1_o3 ==
       heli_q8_oppgave3_B.UnitDelay_g);

    /* UnitDelay: '<S10>/Unit Delay' */
    heli_q8_oppgave3_B.UnitDelay_gs = heli_q8_oppgave3_DW.UnitDelay_DSTATE_j;

    /* RelationalOperator: '<S10>/Relational Operator' */
    heli_q8_oppgave3_B.RelationalOperator_k =
      (heli_q8_oppgave3_B.StreamFormattedRead1_o4 ==
       heli_q8_oppgave3_B.UnitDelay_gs);

    /* UnitDelay: '<S11>/Unit Delay' */
    heli_q8_oppgave3_B.UnitDelay_m = heli_q8_oppgave3_DW.UnitDelay_DSTATE_a;

    /* RelationalOperator: '<S11>/Relational Operator' */
    heli_q8_oppgave3_B.RelationalOperator_l =
      (heli_q8_oppgave3_B.StreamFormattedRead1_o5 ==
       heli_q8_oppgave3_B.UnitDelay_m);

    /* UnitDelay: '<S12>/Unit Delay' */
    heli_q8_oppgave3_B.UnitDelay_d = heli_q8_oppgave3_DW.UnitDelay_DSTATE_pf;

    /* RelationalOperator: '<S12>/Relational Operator' */
    heli_q8_oppgave3_B.RelationalOperator_b =
      (heli_q8_oppgave3_B.StreamFormattedRead1_o6 ==
       heli_q8_oppgave3_B.UnitDelay_d);

    /* UnitDelay: '<S13>/Unit Delay' */
    heli_q8_oppgave3_B.UnitDelay_c = heli_q8_oppgave3_DW.UnitDelay_DSTATE_g;

    /* RelationalOperator: '<S13>/Relational Operator' */
    heli_q8_oppgave3_B.RelationalOperator_d =
      (heli_q8_oppgave3_B.StreamFormattedRead1_o7 ==
       heli_q8_oppgave3_B.UnitDelay_c);

    /* Logic: '<S5>/Logical Operator1' incorporates:
     *  Logic: '<S5>/Logical Operator'
     */
    heli_q8_oppgave3_B.LogicalOperator1 =
      ((!heli_q8_oppgave3_B.RelationalOperator) ||
       (!heli_q8_oppgave3_B.RelationalOperator_m) ||
       (!heli_q8_oppgave3_B.RelationalOperator_k) ||
       (!heli_q8_oppgave3_B.RelationalOperator_l) ||
       (!heli_q8_oppgave3_B.RelationalOperator_b) ||
       (!heli_q8_oppgave3_B.RelationalOperator_d));

    /* Outputs for Enabled SubSystem: '<S5>/Skip to next line' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    if (heli_q8_oppgave3_B.StreamFormattedRead1_o10) {
      /* S-Function (stream_formatted_read_block): '<S14>/Stream Formatted Read' incorporates:
       *  S-Function (stream_call_block): '<S5>/Stream Call2'
       *  S-Function (stream_formatted_read_block): '<S5>/Stream Formatted Read1'
       */
      {
        if (((t_stream_ptr)rtb_StreamCall2_o1) != NULL) {
          stream_scan_utf8_char_array(*((t_stream_ptr)rtb_StreamCall2_o1),
            heli_q8_oppgave3_P.StreamFormattedRead_MaxUnits,
            &rtb_StreamFormattedRead_o2, " %*[^\r]"
            );
        } else {
          rtb_StreamFormattedRead_o2 = 0;
        }
      }

      if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
        srUpdateBC(heli_q8_oppgave3_DW.Skiptonextline_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S5>/Skip to next line' */

    /* S-Function (stop_with_error_block): '<S5>/Stop with Call Error1' */

    /* S-Function Block: heli_q8_oppgave3/IMU3/Stop with Call Error1 (stop_with_error_block) */
    {
      if (rtb_StreamCall2_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall2_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S5>/Stop with Read Error1' */

    /* S-Function Block: heli_q8_oppgave3/IMU3/Stop with Read Error1 (stop_with_error_block) */
    {
      if (rtb_StreamFormattedRead1_o12 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamFormattedRead1_o12,
          _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }
  }

  /* Integrator: '<Root>/Integrator' */
  heli_q8_oppgave3_B.Integrator[0] = heli_q8_oppgave3_X.Integrator_CSTATE[0];
  heli_q8_oppgave3_B.Integrator[1] = heli_q8_oppgave3_X.Integrator_CSTATE[1];

  /* RateTransition: '<S15>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
    if (heli_q8_oppgave3_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S15>/Rate Transition: x' */
      heli_q8_oppgave3_B.RateTransitionx =
        heli_q8_oppgave3_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S15>/Dead Zone: x' */
    if (heli_q8_oppgave3_B.RateTransitionx > heli_q8_oppgave3_P.DeadZonex_End) {
      /* Saturate: '<S4>/Front motor: Saturation' */
      rtb_FrontmotorSaturation = heli_q8_oppgave3_B.RateTransitionx -
        heli_q8_oppgave3_P.DeadZonex_End;
    } else if (heli_q8_oppgave3_B.RateTransitionx >=
               heli_q8_oppgave3_P.DeadZonex_Start) {
      /* Saturate: '<S4>/Front motor: Saturation' */
      rtb_FrontmotorSaturation = 0.0;
    } else {
      /* Saturate: '<S4>/Front motor: Saturation' */
      rtb_FrontmotorSaturation = heli_q8_oppgave3_B.RateTransitionx -
        heli_q8_oppgave3_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S15>/Dead Zone: x' */

    /* Gain: '<S15>/Joystick_gain_x' incorporates:
     *  Gain: '<S15>/Gain: x'
     */
    heli_q8_oppgave3_B.Joystick_gain_x = heli_q8_oppgave3_P.Gainx_Gain *
      rtb_FrontmotorSaturation * heli_q8_oppgave3_P.Joystick_gain_x;
  }

  /* End of RateTransition: '<S15>/Rate Transition: x' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (heli_q8_oppgave3_P.Constant1_Value > heli_q8_oppgave3_P.Switch_Threshold)
  {
    /* Step: '<S6>/Step2' incorporates:
     *  Step: '<S6>/Step3'
     *  Step: '<S6>/Step4'
     *  Step: '<S6>/Step5'
     */
    az = heli_q8_oppgave3_M->Timing.t[0];
    if (az < heli_q8_oppgave3_P.Step2_Time) {
      phi = heli_q8_oppgave3_P.Step2_Y0;
    } else {
      phi = heli_q8_oppgave3_P.Step2_YFinal;
    }

    /* End of Step: '<S6>/Step2' */

    /* Step: '<S6>/Step3' */
    if (az < heli_q8_oppgave3_P.Step3_Time) {
      theta = heli_q8_oppgave3_P.Step3_Y0;
    } else {
      theta = heli_q8_oppgave3_P.Step3_YFinal;
    }

    /* Step: '<S6>/Step4' */
    if (az < heli_q8_oppgave3_P.Step4_Time) {
      euler_rates_tmp = heli_q8_oppgave3_P.Step4_Y0;
    } else {
      euler_rates_tmp = heli_q8_oppgave3_P.Step4_YFinal;
    }

    /* Step: '<S6>/Step5' */
    if (az < heli_q8_oppgave3_P.Step5_Time) {
      az = heli_q8_oppgave3_P.Step5_Y0;
    } else {
      az = heli_q8_oppgave3_P.Step5_YFinal;
    }

    /* Switch: '<S6>/Switch' incorporates:
     *  Sum: '<S6>/y'
     */
    heli_q8_oppgave3_B.Switch = ((phi + theta) + euler_rates_tmp) + az;
  } else {
    /* Switch: '<S6>/Switch' */
    heli_q8_oppgave3_B.Switch = heli_q8_oppgave3_B.Joystick_gain_x;
  }

  /* End of Switch: '<S6>/Switch' */

  /* StateSpace: '<S7>/State-Space' */
  for (iy = 0; iy < 5; iy++) {
    rtb_StateSpace[iy] = 0.0;
    for (ci = 0; ci < 5; ci++) {
      rtb_StateSpace[iy] += heli_q8_oppgave3_P.StateSpace_C[ci * 5 + iy] *
        heli_q8_oppgave3_X.StateSpace_CSTATE[ci];
    }
  }

  /* End of StateSpace: '<S7>/State-Space' */
  for (iy = 0; iy < 2; iy++) {
    /* Gain: '<S7>/Gain1' */
    heli_q8_oppgave3_B.Gain1_b[iy] = 0.0;
    for (ci = 0; ci < 5; ci++) {
      heli_q8_oppgave3_B.Gain1_b[iy] += heli_q8_oppgave3_P.C_aug[(ci << 1) + iy]
        * rtb_StateSpace[ci];
    }

    /* End of Gain: '<S7>/Gain1' */
  }

  /* RateTransition: '<S15>/Rate Transition: y' */
  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
    if (heli_q8_oppgave3_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S15>/Rate Transition: y' */
      heli_q8_oppgave3_B.RateTransitiony =
        heli_q8_oppgave3_DW.RateTransitiony_Buffer0;
    }

    /* DeadZone: '<S15>/Dead Zone: y' */
    if (heli_q8_oppgave3_B.RateTransitiony > heli_q8_oppgave3_P.DeadZoney_End) {
      /* Saturate: '<S4>/Front motor: Saturation' */
      rtb_FrontmotorSaturation = heli_q8_oppgave3_B.RateTransitiony -
        heli_q8_oppgave3_P.DeadZoney_End;
    } else if (heli_q8_oppgave3_B.RateTransitiony >=
               heli_q8_oppgave3_P.DeadZoney_Start) {
      /* Saturate: '<S4>/Front motor: Saturation' */
      rtb_FrontmotorSaturation = 0.0;
    } else {
      /* Saturate: '<S4>/Front motor: Saturation' */
      rtb_FrontmotorSaturation = heli_q8_oppgave3_B.RateTransitiony -
        heli_q8_oppgave3_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S15>/Dead Zone: y' */

    /* Gain: '<S15>/Joystick_gain_y' incorporates:
     *  Gain: '<S15>/Gain: y'
     */
    heli_q8_oppgave3_B.Joystick_gain_y = heli_q8_oppgave3_P.Gainy_Gain *
      rtb_FrontmotorSaturation * heli_q8_oppgave3_P.Joystick_gain_y;

    /* Gain: '<S6>/Gain2' */
    heli_q8_oppgave3_B.Gain2_p = heli_q8_oppgave3_P.Gain2_Gain_a *
      heli_q8_oppgave3_B.Joystick_gain_y;
  }

  /* End of RateTransition: '<S15>/Rate Transition: y' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (heli_q8_oppgave3_P.Constant1_Value > heli_q8_oppgave3_P.Switch1_Threshold)
  {
    /* Step: '<S6>/Step' incorporates:
     *  Step: '<S6>/Step1'
     *  Step: '<S6>/Step6'
     *  Step: '<S6>/Step7'
     *  Step: '<S6>/Step8'
     */
    az = heli_q8_oppgave3_M->Timing.t[0];
    if (az < heli_q8_oppgave3_P.Step_Time) {
      phi = heli_q8_oppgave3_P.Step_Y0;
    } else {
      phi = heli_q8_oppgave3_P.Step_YFinal;
    }

    /* End of Step: '<S6>/Step' */

    /* Step: '<S6>/Step1' */
    if (az < heli_q8_oppgave3_P.Step1_Time) {
      theta = heli_q8_oppgave3_P.Step1_Y0;
    } else {
      theta = heli_q8_oppgave3_P.Step1_YFinal;
    }

    /* Step: '<S6>/Step6' */
    if (az < heli_q8_oppgave3_P.Step6_Time) {
      euler_rates_tmp = heli_q8_oppgave3_P.Step6_Y0;
    } else {
      euler_rates_tmp = heli_q8_oppgave3_P.Step6_YFinal;
    }

    /* Step: '<S6>/Step7' */
    if (az < heli_q8_oppgave3_P.Step7_Time) {
      euler_rates_tmp_0 = heli_q8_oppgave3_P.Step7_Y0;
    } else {
      euler_rates_tmp_0 = heli_q8_oppgave3_P.Step7_YFinal;
    }

    /* Step: '<S6>/Step8' */
    if (az < heli_q8_oppgave3_P.Step8_Time) {
      az = heli_q8_oppgave3_P.Step8_Y0;
    } else {
      az = heli_q8_oppgave3_P.Step8_YFinal;
    }

    /* Switch: '<S6>/Switch1' incorporates:
     *  Sum: '<S6>/y1'
     */
    heli_q8_oppgave3_B.Switch1 = (((phi + theta) + euler_rates_tmp) +
      euler_rates_tmp_0) + az;
  } else {
    /* Switch: '<S6>/Switch1' */
    heli_q8_oppgave3_B.Switch1 = heli_q8_oppgave3_B.Gain2_p;
  }

  /* End of Switch: '<S6>/Switch1' */
  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
  }

  /* SignalConversion generated from: '<Root>/K' */
  rtb_StateSpace_0[0] = heli_q8_oppgave3_B.PitchCounttorad;
  rtb_StateSpace_0[1] = heli_q8_oppgave3_B.PitchTransferFcn;
  rtb_StateSpace_0[2] = heli_q8_oppgave3_B.TransferFcn;

  /* Gain: '<Root>/F' incorporates:
   *  SignalConversion generated from: '<Root>/F'
   */
  u_tmp[0] = heli_q8_oppgave3_P.F_aug[0] * heli_q8_oppgave3_B.Switch +
    heli_q8_oppgave3_P.F_aug[2] * heli_q8_oppgave3_B.Switch1;

  /* SignalConversion generated from: '<Root>/K' */
  rtb_StateSpace_0[3] = heli_q8_oppgave3_B.Integrator[0];

  /* Gain: '<Root>/F' incorporates:
   *  SignalConversion generated from: '<Root>/F'
   */
  u_tmp[1] = heli_q8_oppgave3_P.F_aug[1] * heli_q8_oppgave3_B.Switch;
  u_tmp[1] += heli_q8_oppgave3_P.F_aug[3] * heli_q8_oppgave3_B.Switch1;

  /* SignalConversion generated from: '<Root>/K' */
  rtb_StateSpace_0[4] = heli_q8_oppgave3_B.Integrator[1];
  for (iy = 0; iy < 2; iy++) {
    /* Sum: '<Root>/Sum' incorporates:
     *  Gain: '<Root>/F'
     *  Gain: '<Root>/K'
     */
    az = 0.0;
    for (ci = 0; ci < 5; ci++) {
      az += heli_q8_oppgave3_P.K_aug[(ci << 1) + iy] * rtb_StateSpace_0[ci];
    }

    heli_q8_oppgave3_B.u[iy] = u_tmp[iy] - az;

    /* End of Sum: '<Root>/Sum' */
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  heli_q8_oppgave3_B.Sum1 = heli_q8_oppgave3_B.u[0] + heli_q8_oppgave3_P.Vs_0;

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  heli_q8_oppgave3_B.Backgain = (heli_q8_oppgave3_B.Sum1 + heli_q8_oppgave3_B.u
    [1]) * heli_q8_oppgave3_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  heli_q8_oppgave3_B.Frontgain = (heli_q8_oppgave3_B.Sum1 -
    heli_q8_oppgave3_B.u[1]) * heli_q8_oppgave3_P.Frontgain_Gain;
  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
  }

  /* SignalConversion generated from: '<S7>/K1' incorporates:
   *  Integrator: '<S7>/Integrator'
   */
  rtb_StateSpace_0[0] = rtb_StateSpace[0];
  rtb_StateSpace_0[1] = rtb_StateSpace[1];
  rtb_StateSpace_0[2] = rtb_StateSpace[2];
  rtb_StateSpace_0[3] = heli_q8_oppgave3_X.Integrator_CSTATE_i[0];
  rtb_StateSpace_0[4] = heli_q8_oppgave3_X.Integrator_CSTATE_i[1];
  for (iy = 0; iy < 2; iy++) {
    /* Sum: '<S7>/Sum2' incorporates:
     *  Gain: '<S7>/F1'
     *  Gain: '<S7>/K1'
     */
    az = 0.0;
    for (ci = 0; ci < 5; ci++) {
      az += heli_q8_oppgave3_P.K_aug[(ci << 1) + iy] * rtb_StateSpace_0[ci];
    }

    heli_q8_oppgave3_B.u_d[iy] = u_tmp[iy] - az;

    /* End of Sum: '<S7>/Sum2' */
  }

  /* SignalConversion generated from: '<S7>/Integrator' incorporates:
   *  Sum: '<S7>/Sum1'
   *  Sum: '<S7>/Sum4'
   */
  heli_q8_oppgave3_B.TmpSignalConversionAtIntegrator[0] =
    heli_q8_oppgave3_B.Switch - rtb_StateSpace[0];
  heli_q8_oppgave3_B.TmpSignalConversionAtIntegrator[1] =
    heli_q8_oppgave3_B.Switch1 - rtb_StateSpace[2];

  /* SignalConversion generated from: '<Root>/Integrator' incorporates:
   *  Sum: '<Root>/Sum3'
   *  Sum: '<Root>/Sum4'
   */
  heli_q8_oppgave3_B.TmpSignalConversionAtIntegrat_p[0] =
    heli_q8_oppgave3_B.Switch - heli_q8_oppgave3_B.PitchCounttorad;
  heli_q8_oppgave3_B.TmpSignalConversionAtIntegrat_p[1] =
    heli_q8_oppgave3_B.Switch1 - heli_q8_oppgave3_B.TransferFcn;
  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
    /* SignalConversion generated from: '<S2>/To File' */
    rtb_TmpSignalConversionAtToFile[0] = heli_q8_oppgave3_B.TravelCounttorad;
    rtb_TmpSignalConversionAtToFile[1] = heli_q8_oppgave3_B.TravelTransferFcn;
    rtb_TmpSignalConversionAtToFile[2] = heli_q8_oppgave3_B.PitchCounttorad;
    rtb_TmpSignalConversionAtToFile[3] = heli_q8_oppgave3_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtToFile[4] = heli_q8_oppgave3_B.ElevationCounttorad;
    rtb_TmpSignalConversionAtToFile[5] = heli_q8_oppgave3_B.TransferFcn;
    rtb_TmpSignalConversionAtToFile[6] = heli_q8_oppgave3_B.u[1];
    rtb_TmpSignalConversionAtToFile[7] = heli_q8_oppgave3_B.Sum1;
    rtb_TmpSignalConversionAtToFile[8] = heli_q8_oppgave3_B.Switch1;
    rtb_TmpSignalConversionAtToFile[9] = heli_q8_oppgave3_B.Switch;
    rtb_TmpSignalConversionAtToFile[10] = heli_q8_oppgave3_B.Frontgain;
    rtb_TmpSignalConversionAtToFile[11] = heli_q8_oppgave3_B.Backgain;
    rtb_TmpSignalConversionAtToFile[12] = heli_q8_oppgave3_B.Switch;
    rtb_TmpSignalConversionAtToFile[13] = heli_q8_oppgave3_B.Switch1;
    rtb_TmpSignalConversionAtToFile[14] = heli_q8_oppgave3_B.Gain1_b[0];
    rtb_TmpSignalConversionAtToFile[15] = heli_q8_oppgave3_B.Gain1_b[1];

    /* ToFile: '<S2>/To File' */
    if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
      if (rtmIsMajorTimeStep(heli_q8_oppgave3_M) ) {
        {
          if (!(++heli_q8_oppgave3_DW.ToFile_IWORK.Decimation % 1) &&
              (heli_q8_oppgave3_DW.ToFile_IWORK.Count * (16 + 1)) + 1 <
              100000000 ) {
            FILE *fp = (FILE *) heli_q8_oppgave3_DW.ToFile_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[16 + 1];
              heli_q8_oppgave3_DW.ToFile_IWORK.Decimation = 0;
              u[0] = heli_q8_oppgave3_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFile[0];
              u[2] = rtb_TmpSignalConversionAtToFile[1];
              u[3] = rtb_TmpSignalConversionAtToFile[2];
              u[4] = rtb_TmpSignalConversionAtToFile[3];
              u[5] = rtb_TmpSignalConversionAtToFile[4];
              u[6] = rtb_TmpSignalConversionAtToFile[5];
              u[7] = rtb_TmpSignalConversionAtToFile[6];
              u[8] = rtb_TmpSignalConversionAtToFile[7];
              u[9] = rtb_TmpSignalConversionAtToFile[8];
              u[10] = rtb_TmpSignalConversionAtToFile[9];
              u[11] = rtb_TmpSignalConversionAtToFile[10];
              u[12] = rtb_TmpSignalConversionAtToFile[11];
              u[13] = rtb_TmpSignalConversionAtToFile[12];
              u[14] = rtb_TmpSignalConversionAtToFile[13];
              u[15] = rtb_TmpSignalConversionAtToFile[14];
              u[16] = rtb_TmpSignalConversionAtToFile[15];
              if (fwrite(u, sizeof(real_T), 16 + 1, fp) != 16 + 1) {
                rtmSetErrorStatus(heli_q8_oppgave3_M,
                                  "Error writing to MAT-file helicopter_state_log.mat");
                return;
              }

              if (((++heli_q8_oppgave3_DW.ToFile_IWORK.Count) * (16 + 1))+1 >=
                  100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file helicopter_state_log.mat.\n");
              }
            }
          }
        }
      }
    }
  }

  /* TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  heli_q8_oppgave3_B.ElevationTransferFcn = 0.0;
  heli_q8_oppgave3_B.ElevationTransferFcn +=
    heli_q8_oppgave3_P.ElevationTransferFcn_C *
    heli_q8_oppgave3_X.ElevationTransferFcn_CSTATE;
  heli_q8_oppgave3_B.ElevationTransferFcn +=
    heli_q8_oppgave3_P.ElevationTransferFcn_D *
    heli_q8_oppgave3_B.ElevationCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
    /* Saturate: '<S4>/Front motor: Saturation' */
    if (0.0 > heli_q8_oppgave3_P.FrontmotorSaturation_UpperSat) {
      /* Saturate: '<S4>/Front motor: Saturation' */
      rtb_FrontmotorSaturation =
        heli_q8_oppgave3_P.FrontmotorSaturation_UpperSat;
    } else if (0.0 < heli_q8_oppgave3_P.FrontmotorSaturation_LowerSat) {
      /* Saturate: '<S4>/Front motor: Saturation' */
      rtb_FrontmotorSaturation =
        heli_q8_oppgave3_P.FrontmotorSaturation_LowerSat;
    } else {
      /* Saturate: '<S4>/Front motor: Saturation' */
      rtb_FrontmotorSaturation = 0.0;
    }

    /* End of Saturate: '<S4>/Front motor: Saturation' */

    /* Saturate: '<S4>/Back motor: Saturation' */
    if (0.0 > heli_q8_oppgave3_P.BackmotorSaturation_UpperSat) {
      /* Saturate: '<S4>/Back motor: Saturation' */
      rtb_BackmotorSaturation = heli_q8_oppgave3_P.BackmotorSaturation_UpperSat;
    } else if (0.0 < heli_q8_oppgave3_P.BackmotorSaturation_LowerSat) {
      /* Saturate: '<S4>/Back motor: Saturation' */
      rtb_BackmotorSaturation = heli_q8_oppgave3_P.BackmotorSaturation_LowerSat;
    } else {
      /* Saturate: '<S4>/Back motor: Saturation' */
      rtb_BackmotorSaturation = 0.0;
    }

    /* End of Saturate: '<S4>/Back motor: Saturation' */

    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: heli_q8_oppgave3/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_oppgave3_DW.HILWriteAnalog_Buffer[0] = rtb_FrontmotorSaturation;
      heli_q8_oppgave3_DW.HILWriteAnalog_Buffer[1] = rtb_BackmotorSaturation;
      result = hil_write_analog(heli_q8_oppgave3_DW.HILInitialize_Card,
        heli_q8_oppgave3_P.HILWriteAnalog_channels, 2,
        &heli_q8_oppgave3_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
      }
    }
  }
}

/* Model update function for TID0 */
void heli_q8_oppgave3_update0(void)    /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
    /* Update for UnitDelay: '<S8>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE =
      heli_q8_oppgave3_B.StreamFormattedRead1_o2;

    /* Update for UnitDelay: '<S9>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE_p =
      heli_q8_oppgave3_B.StreamFormattedRead1_o3;

    /* Update for UnitDelay: '<S10>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE_j =
      heli_q8_oppgave3_B.StreamFormattedRead1_o4;

    /* Update for UnitDelay: '<S11>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE_a =
      heli_q8_oppgave3_B.StreamFormattedRead1_o5;

    /* Update for UnitDelay: '<S12>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE_pf =
      heli_q8_oppgave3_B.StreamFormattedRead1_o6;

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE_g =
      heli_q8_oppgave3_B.StreamFormattedRead1_o7;
  }

  if (rtmIsMajorTimeStep(heli_q8_oppgave3_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_oppgave3_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_oppgave3_M->Timing.clockTick0)) {
    ++heli_q8_oppgave3_M->Timing.clockTickH0;
  }

  heli_q8_oppgave3_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_oppgave3_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_oppgave3_M->Timing.clockTick1)) {
    ++heli_q8_oppgave3_M->Timing.clockTickH1;
  }

  heli_q8_oppgave3_M->Timing.t[1] = heli_q8_oppgave3_M->Timing.clockTick1 *
    heli_q8_oppgave3_M->Timing.stepSize1 +
    heli_q8_oppgave3_M->Timing.clockTickH1 *
    heli_q8_oppgave3_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_oppgave3_derivatives(void)
{
  XDot_heli_q8_oppgave3_T *_rtXdot;
  int_T is;
  int_T ri;
  _rtXdot = ((XDot_heli_q8_oppgave3_T *) heli_q8_oppgave3_M->derivs);

  /* Derivatives for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_oppgave3_P.PitchTransferFcn_A *
    heli_q8_oppgave3_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_oppgave3_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += heli_q8_oppgave3_P.TransferFcn_A *
    heli_q8_oppgave3_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += heli_q8_oppgave3_B.ElevationTransferFcn;

  /* Derivatives for TransferFcn: '<S4>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_oppgave3_P.TravelTransferFcn_A *
    heli_q8_oppgave3_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_oppgave3_B.TravelCounttorad;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] =
    heli_q8_oppgave3_B.TmpSignalConversionAtIntegrat_p[0];
  _rtXdot->Integrator_CSTATE[1] =
    heli_q8_oppgave3_B.TmpSignalConversionAtIntegrat_p[1];

  /* Derivatives for StateSpace: '<S7>/State-Space' */
  for (is = 0; is < 5; is++) {
    _rtXdot->StateSpace_CSTATE[is] = 0.0;
  }

  for (ri = 0; ri < 5; ri++) {
    for (is = 0; is < 5; is++) {
      _rtXdot->StateSpace_CSTATE[ri] += heli_q8_oppgave3_P.A_aug[is * 5 + ri] *
        heli_q8_oppgave3_X.StateSpace_CSTATE[is];
    }

    _rtXdot->StateSpace_CSTATE[ri] += heli_q8_oppgave3_P.B_aug[ri] *
      heli_q8_oppgave3_B.u_d[0];
    _rtXdot->StateSpace_CSTATE[ri] += heli_q8_oppgave3_P.B_aug[ri + 5] *
      heli_q8_oppgave3_B.u_d[1];
  }

  /* End of Derivatives for StateSpace: '<S7>/State-Space' */

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE_i[0] =
    heli_q8_oppgave3_B.TmpSignalConversionAtIntegrator[0];
  _rtXdot->Integrator_CSTATE_i[1] =
    heli_q8_oppgave3_B.TmpSignalConversionAtIntegrator[1];

  /* Derivatives for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    heli_q8_oppgave3_P.ElevationTransferFcn_A *
    heli_q8_oppgave3_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_oppgave3_B.ElevationCounttorad;
}

/* Model output function for TID2 */
void heli_q8_oppgave3_output2(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S15>/Game Controller' */

  /* S-Function Block: heli_q8_oppgave3/Reference1/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_oppgave3_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll
        (heli_q8_oppgave3_DW.GameController_Controller, &state, &new_data);
      if (result < 0) {
        new_data = false;
      }

      rtb_GameController_o4 = state.x;
      rtb_GameController_o5 = state.y;
    } else {
      rtb_GameController_o4 = 0;
      rtb_GameController_o5 = 0;
    }
  }

  /* RateTransition: '<S15>/Rate Transition: x' */
  heli_q8_oppgave3_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S15>/Rate Transition: y' */
  heli_q8_oppgave3_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void heli_q8_oppgave3_update2(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_oppgave3_M->Timing.clockTick2)) {
    ++heli_q8_oppgave3_M->Timing.clockTickH2;
  }

  heli_q8_oppgave3_M->Timing.t[2] = heli_q8_oppgave3_M->Timing.clockTick2 *
    heli_q8_oppgave3_M->Timing.stepSize2 +
    heli_q8_oppgave3_M->Timing.clockTickH2 *
    heli_q8_oppgave3_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_oppgave3_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_oppgave3_output0();
    break;

   case 2 :
    heli_q8_oppgave3_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_oppgave3_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_oppgave3_update0();
    break;

   case 2 :
    heli_q8_oppgave3_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_oppgave3_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_oppgave3/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_oppgave3_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (heli_q8_oppgave3_DW.HILInitialize_Card, "update_rate=normal;decimation=1",
       32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_oppgave3_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
      return;
    }

    if ((heli_q8_oppgave3_P.HILInitialize_AIPStart && !is_switching) ||
        (heli_q8_oppgave3_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_oppgave3_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (heli_q8_oppgave3_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_oppgave3_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_oppgave3_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (heli_q8_oppgave3_DW.HILInitialize_Card,
         heli_q8_oppgave3_P.HILInitialize_AIChannels, 8U,
         &heli_q8_oppgave3_DW.HILInitialize_AIMinimums[0],
         &heli_q8_oppgave3_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_oppgave3_P.HILInitialize_AOPStart && !is_switching) ||
        (heli_q8_oppgave3_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_oppgave3_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (heli_q8_oppgave3_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_oppgave3_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_oppgave3_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (heli_q8_oppgave3_DW.HILInitialize_Card,
         heli_q8_oppgave3_P.HILInitialize_AOChannels, 8U,
         &heli_q8_oppgave3_DW.HILInitialize_AOMinimums[0],
         &heli_q8_oppgave3_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_oppgave3_P.HILInitialize_AOStart && !is_switching) ||
        (heli_q8_oppgave3_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_oppgave3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_oppgave3_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(heli_q8_oppgave3_DW.HILInitialize_Card,
        heli_q8_oppgave3_P.HILInitialize_AOChannels, 8U,
        &heli_q8_oppgave3_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_oppgave3_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_oppgave3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_oppgave3_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_oppgave3_DW.HILInitialize_Card,
         heli_q8_oppgave3_P.HILInitialize_AOChannels, 8U,
         &heli_q8_oppgave3_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_oppgave3_P.HILInitialize_EIPStart && !is_switching) ||
        (heli_q8_oppgave3_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_oppgave3_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_oppgave3_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_oppgave3_DW.HILInitialize_Card,
         heli_q8_oppgave3_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_oppgave3_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_oppgave3_P.HILInitialize_EIStart && !is_switching) ||
        (heli_q8_oppgave3_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_oppgave3_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_q8_oppgave3_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(heli_q8_oppgave3_DW.HILInitialize_Card,
        heli_q8_oppgave3_P.HILInitialize_EIChannels, 8U,
        &heli_q8_oppgave3_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_oppgave3_P.HILInitialize_POPStart && !is_switching) ||
        (heli_q8_oppgave3_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_oppgave3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_oppgave3_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_oppgave3_DW.HILInitialize_Card,
        heli_q8_oppgave3_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &heli_q8_oppgave3_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          heli_q8_oppgave3_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &heli_q8_oppgave3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            heli_q8_oppgave3_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            heli_q8_oppgave3_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = heli_q8_oppgave3_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_oppgave3_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            heli_q8_oppgave3_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              heli_q8_oppgave3_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_oppgave3_DW.HILInitialize_Card,
          &heli_q8_oppgave3_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &heli_q8_oppgave3_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_oppgave3_DW.HILInitialize_Card,
          &heli_q8_oppgave3_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_oppgave3_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_oppgave3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_oppgave3_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_oppgave3_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_oppgave3_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_oppgave3_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_oppgave3_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_oppgave3_DW.HILInitialize_Card,
        heli_q8_oppgave3_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &heli_q8_oppgave3_DW.HILInitialize_POModeValues
        [0],
        (t_pwm_alignment *) &heli_q8_oppgave3_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_oppgave3_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &heli_q8_oppgave3_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_oppgave3_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_oppgave3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_oppgave3_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_oppgave3_DW.HILInitialize_Card,
        heli_q8_oppgave3_P.HILInitialize_POChannels, 8U,
        &heli_q8_oppgave3_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_oppgave3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_oppgave3_P.HILInitialize_POStart && !is_switching) ||
        (heli_q8_oppgave3_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_oppgave3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_oppgave3_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(heli_q8_oppgave3_DW.HILInitialize_Card,
        heli_q8_oppgave3_P.HILInitialize_POChannels, 8U,
        &heli_q8_oppgave3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_oppgave3_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_oppgave3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_oppgave3_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_oppgave3_DW.HILInitialize_Card,
         heli_q8_oppgave3_P.HILInitialize_POChannels, 8U,
         &heli_q8_oppgave3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_oppgave3/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (heli_q8_oppgave3_DW.HILInitialize_Card,
       heli_q8_oppgave3_P.HILReadEncoderTimebase_SamplesI,
       heli_q8_oppgave3_P.HILReadEncoderTimebase_Channels, 3,
       &heli_q8_oppgave3_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (heli_q8_oppgave3_DW.HILReadEncoderTimebase_Task,
         (t_buffer_overflow_mode)
         (heli_q8_oppgave3_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
    }
  }

  /* Start for S-Function (stream_call_block): '<S5>/Stream Call2' incorporates:
   *  Constant: '<S5>/Constant4'
   *  S-Function (string_constant_block): '<S5>/String Constant1'
   */

  /* S-Function Block: heli_q8_oppgave3/IMU3/Stream Call2 (stream_call_block) */
  {
    heli_q8_oppgave3_DW.StreamCall2_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_oppgave3_DW.StreamCall2_Stream = NULL;
  }

  /* Start for RateTransition: '<S15>/Rate Transition: x' */
  heli_q8_oppgave3_B.RateTransitionx =
    heli_q8_oppgave3_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S15>/Rate Transition: y' */
  heli_q8_oppgave3_B.RateTransitiony =
    heli_q8_oppgave3_P.RateTransitiony_InitialConditio;

  /* Start for ToFile: '<S2>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "helicopter_state_log.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_oppgave3_M,
                        "Error creating .mat file helicopter_state_log.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 16 + 1, 0, "var")) {
      rtmSetErrorStatus(heli_q8_oppgave3_M,
                        "Error writing mat file header to file helicopter_state_log.mat");
      return;
    }

    heli_q8_oppgave3_DW.ToFile_IWORK.Count = 0;
    heli_q8_oppgave3_DW.ToFile_IWORK.Decimation = -1;
    heli_q8_oppgave3_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for S-Function (game_controller_block): '<S15>/Game Controller' */

  /* S-Function Block: heli_q8_oppgave3/Reference1/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_oppgave3_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (heli_q8_oppgave3_P.GameController_ControllerNumber,
         heli_q8_oppgave3_P.GameController_BufferSize, deadzone, saturation,
         heli_q8_oppgave3_P.GameController_AutoCenter, 0, 1.0,
         &heli_q8_oppgave3_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
      }
    }
  }

  {
    int_T is;

    /* InitializeConditions for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
    heli_q8_oppgave3_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
    heli_q8_oppgave3_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Travel: Transfer Fcn' */
    heli_q8_oppgave3_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE =
      heli_q8_oppgave3_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE_p =
      heli_q8_oppgave3_P.UnitDelay_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE_j =
      heli_q8_oppgave3_P.UnitDelay_InitialCondition_i;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE_a =
      heli_q8_oppgave3_P.UnitDelay_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE_pf =
      heli_q8_oppgave3_P.UnitDelay_InitialCondition_k;

    /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
    heli_q8_oppgave3_DW.UnitDelay_DSTATE_g =
      heli_q8_oppgave3_P.UnitDelay_InitialCondition_kh;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    heli_q8_oppgave3_X.Integrator_CSTATE[0] = heli_q8_oppgave3_P.Integrator_IC;
    heli_q8_oppgave3_X.Integrator_CSTATE[1] = heli_q8_oppgave3_P.Integrator_IC;

    /* InitializeConditions for RateTransition: '<S15>/Rate Transition: x' */
    heli_q8_oppgave3_DW.RateTransitionx_Buffer0 =
      heli_q8_oppgave3_P.RateTransitionx_InitialConditio;

    /* InitializeConditions for StateSpace: '<S7>/State-Space' */
    for (is = 0; is < 5; is++) {
      heli_q8_oppgave3_X.StateSpace_CSTATE[is] =
        heli_q8_oppgave3_P.StateSpace_InitialCondition;
    }

    /* End of InitializeConditions for StateSpace: '<S7>/State-Space' */

    /* InitializeConditions for RateTransition: '<S15>/Rate Transition: y' */
    heli_q8_oppgave3_DW.RateTransitiony_Buffer0 =
      heli_q8_oppgave3_P.RateTransitiony_InitialConditio;

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    heli_q8_oppgave3_X.Integrator_CSTATE_i[0] =
      heli_q8_oppgave3_P.Integrator_IC_d;
    heli_q8_oppgave3_X.Integrator_CSTATE_i[1] =
      heli_q8_oppgave3_P.Integrator_IC_d;

    /* InitializeConditions for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
    heli_q8_oppgave3_X.ElevationTransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void heli_q8_oppgave3_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_oppgave3/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_oppgave3_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_oppgave3_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_oppgave3_P.HILInitialize_AOTerminate && !is_switching) ||
        (heli_q8_oppgave3_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_oppgave3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_oppgave3_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((heli_q8_oppgave3_P.HILInitialize_POTerminate && !is_switching) ||
        (heli_q8_oppgave3_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_oppgave3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_oppgave3_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_oppgave3_DW.HILInitialize_Card
                         , heli_q8_oppgave3_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , heli_q8_oppgave3_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_oppgave3_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_oppgave3_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_oppgave3_DW.HILInitialize_Card,
            heli_q8_oppgave3_P.HILInitialize_AOChannels,
            num_final_analog_outputs,
            &heli_q8_oppgave3_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_oppgave3_DW.HILInitialize_Card,
            heli_q8_oppgave3_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &heli_q8_oppgave3_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_oppgave3_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_oppgave3_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_oppgave3_DW.HILInitialize_Card);
    hil_close(heli_q8_oppgave3_DW.HILInitialize_Card);
    heli_q8_oppgave3_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S5>/Stream Call2' incorporates:
   *  Constant: '<S5>/Constant4'
   *  S-Function (string_constant_block): '<S5>/String Constant1'
   */

  /* S-Function Block: heli_q8_oppgave3/IMU3/Stream Call2 (stream_call_block) */
  {
    if (heli_q8_oppgave3_DW.StreamCall2_Stream != NULL) {
      stream_close(heli_q8_oppgave3_DW.StreamCall2_Stream);
      heli_q8_oppgave3_DW.StreamCall2_Stream = NULL;
    }
  }

  /* Terminate for ToFile: '<S2>/To File' */
  {
    FILE *fp = (FILE *) heli_q8_oppgave3_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "helicopter_state_log.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_oppgave3_M,
                          "Error closing MAT-file helicopter_state_log.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_oppgave3_M,
                          "Error reopening MAT-file helicopter_state_log.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 16 + 1,
           heli_q8_oppgave3_DW.ToFile_IWORK.Count, "var")) {
        rtmSetErrorStatus(heli_q8_oppgave3_M,
                          "Error writing header for var to MAT-file helicopter_state_log.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_oppgave3_M,
                          "Error closing MAT-file helicopter_state_log.mat");
        return;
      }

      heli_q8_oppgave3_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S15>/Game Controller' */

  /* S-Function Block: heli_q8_oppgave3/Reference1/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_oppgave3_P.GameController_Enabled) {
      game_controller_close(heli_q8_oppgave3_DW.GameController_Controller);
      heli_q8_oppgave3_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_oppgave3_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_oppgave3_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  heli_q8_oppgave3_initialize();
}

void MdlTerminate(void)
{
  heli_q8_oppgave3_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_oppgave3_T *heli_q8_oppgave3(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  heli_q8_oppgave3_P.UnitDelay_InitialCondition = rtNaNF;
  heli_q8_oppgave3_P.UnitDelay_InitialCondition_o = rtNaNF;
  heli_q8_oppgave3_P.UnitDelay_InitialCondition_i = rtNaNF;
  heli_q8_oppgave3_P.UnitDelay_InitialCondition_g = rtNaNF;
  heli_q8_oppgave3_P.UnitDelay_InitialCondition_k = rtNaNF;
  heli_q8_oppgave3_P.UnitDelay_InitialCondition_kh = rtNaNF;

  /* initialize real-time model */
  (void) memset((void *)heli_q8_oppgave3_M, 0,
                sizeof(RT_MODEL_heli_q8_oppgave3_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_oppgave3_M->solverInfo,
                          &heli_q8_oppgave3_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_oppgave3_M->solverInfo, &rtmGetTPtr(heli_q8_oppgave3_M));
    rtsiSetStepSizePtr(&heli_q8_oppgave3_M->solverInfo,
                       &heli_q8_oppgave3_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_oppgave3_M->solverInfo, &heli_q8_oppgave3_M->derivs);
    rtsiSetContStatesPtr(&heli_q8_oppgave3_M->solverInfo, (real_T **)
                         &heli_q8_oppgave3_M->contStates);
    rtsiSetNumContStatesPtr(&heli_q8_oppgave3_M->solverInfo,
      &heli_q8_oppgave3_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_oppgave3_M->solverInfo,
      &heli_q8_oppgave3_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_oppgave3_M->solverInfo,
      &heli_q8_oppgave3_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_oppgave3_M->solverInfo,
      &heli_q8_oppgave3_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_oppgave3_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_oppgave3_M)));
    rtsiSetRTModelPtr(&heli_q8_oppgave3_M->solverInfo, heli_q8_oppgave3_M);
  }

  rtsiSetSimTimeStep(&heli_q8_oppgave3_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_oppgave3_M->intgData.f[0] = heli_q8_oppgave3_M->odeF[0];
  heli_q8_oppgave3_M->contStates = ((real_T *) &heli_q8_oppgave3_X);
  rtsiSetSolverData(&heli_q8_oppgave3_M->solverInfo, (void *)
                    &heli_q8_oppgave3_M->intgData);
  rtsiSetSolverName(&heli_q8_oppgave3_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_oppgave3_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_oppgave3_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_oppgave3_M->Timing.sampleTimes =
      (&heli_q8_oppgave3_M->Timing.sampleTimesArray[0]);
    heli_q8_oppgave3_M->Timing.offsetTimes =
      (&heli_q8_oppgave3_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_oppgave3_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_oppgave3_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_oppgave3_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_oppgave3_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_oppgave3_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_oppgave3_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_oppgave3_M, &heli_q8_oppgave3_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_oppgave3_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      heli_q8_oppgave3_M->Timing.perTaskSampleHitsArray;
    heli_q8_oppgave3_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_oppgave3_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_oppgave3_M, 9999.0);
  heli_q8_oppgave3_M->Timing.stepSize0 = 0.002;
  heli_q8_oppgave3_M->Timing.stepSize1 = 0.002;
  heli_q8_oppgave3_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_oppgave3_M->Sizes.checksums[0] = (3858695019U);
  heli_q8_oppgave3_M->Sizes.checksums[1] = (2474585812U);
  heli_q8_oppgave3_M->Sizes.checksums[2] = (1527850917U);
  heli_q8_oppgave3_M->Sizes.checksums[3] = (3487426430U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    heli_q8_oppgave3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &heli_q8_oppgave3_DW.Skiptonextline_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_q8_oppgave3_M->extModeInfo,
      &heli_q8_oppgave3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_oppgave3_M->extModeInfo,
                        heli_q8_oppgave3_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_oppgave3_M->extModeInfo, rtmGetTPtr(heli_q8_oppgave3_M));
  }

  heli_q8_oppgave3_M->solverInfoPtr = (&heli_q8_oppgave3_M->solverInfo);
  heli_q8_oppgave3_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_oppgave3_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_oppgave3_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_oppgave3_M->blockIO = ((void *) &heli_q8_oppgave3_B);
  (void) memset(((void *) &heli_q8_oppgave3_B), 0,
                sizeof(B_heli_q8_oppgave3_T));

  {
    heli_q8_oppgave3_B.PitchCounttorad = 0.0;
    heli_q8_oppgave3_B.DataTypeConversion2[0] = 0.0;
    heli_q8_oppgave3_B.DataTypeConversion2[1] = 0.0;
    heli_q8_oppgave3_B.DataTypeConversion2[2] = 0.0;
    heli_q8_oppgave3_B.Gain1[0] = 0.0;
    heli_q8_oppgave3_B.Gain1[1] = 0.0;
    heli_q8_oppgave3_B.Gain1[2] = 0.0;
    heli_q8_oppgave3_B.DataTypeConversion1[0] = 0.0;
    heli_q8_oppgave3_B.DataTypeConversion1[1] = 0.0;
    heli_q8_oppgave3_B.DataTypeConversion1[2] = 0.0;
    heli_q8_oppgave3_B.Gain2[0] = 0.0;
    heli_q8_oppgave3_B.Gain2[1] = 0.0;
    heli_q8_oppgave3_B.Gain2[2] = 0.0;
    heli_q8_oppgave3_B.ElevationCounttorad = 0.0;
    heli_q8_oppgave3_B.PitchTransferFcn = 0.0;
    heli_q8_oppgave3_B.TransferFcn = 0.0;
    heli_q8_oppgave3_B.TravelCounttorad = 0.0;
    heli_q8_oppgave3_B.TravelTransferFcn = 0.0;
    heli_q8_oppgave3_B.Integrator[0] = 0.0;
    heli_q8_oppgave3_B.Integrator[1] = 0.0;
    heli_q8_oppgave3_B.RateTransitionx = 0.0;
    heli_q8_oppgave3_B.Joystick_gain_x = 0.0;
    heli_q8_oppgave3_B.Switch = 0.0;
    heli_q8_oppgave3_B.Gain1_b[0] = 0.0;
    heli_q8_oppgave3_B.Gain1_b[1] = 0.0;
    heli_q8_oppgave3_B.RateTransitiony = 0.0;
    heli_q8_oppgave3_B.Joystick_gain_y = 0.0;
    heli_q8_oppgave3_B.Gain2_p = 0.0;
    heli_q8_oppgave3_B.Switch1 = 0.0;
    heli_q8_oppgave3_B.u[0] = 0.0;
    heli_q8_oppgave3_B.u[1] = 0.0;
    heli_q8_oppgave3_B.Sum1 = 0.0;
    heli_q8_oppgave3_B.Backgain = 0.0;
    heli_q8_oppgave3_B.Frontgain = 0.0;
    heli_q8_oppgave3_B.u_d[0] = 0.0;
    heli_q8_oppgave3_B.u_d[1] = 0.0;
    heli_q8_oppgave3_B.TmpSignalConversionAtIntegrator[0] = 0.0;
    heli_q8_oppgave3_B.TmpSignalConversionAtIntegrator[1] = 0.0;
    heli_q8_oppgave3_B.TmpSignalConversionAtIntegrat_p[0] = 0.0;
    heli_q8_oppgave3_B.TmpSignalConversionAtIntegrat_p[1] = 0.0;
    heli_q8_oppgave3_B.ElevationTransferFcn = 0.0;
    heli_q8_oppgave3_B.euler_rates[0] = 0.0;
    heli_q8_oppgave3_B.euler_rates[1] = 0.0;
    heli_q8_oppgave3_B.euler_rates[2] = 0.0;
    heli_q8_oppgave3_B.euler_angles[0] = 0.0;
    heli_q8_oppgave3_B.euler_angles[1] = 0.0;
    heli_q8_oppgave3_B.StreamFormattedRead1_o2 = 0.0F;
    heli_q8_oppgave3_B.StreamFormattedRead1_o3 = 0.0F;
    heli_q8_oppgave3_B.StreamFormattedRead1_o4 = 0.0F;
    heli_q8_oppgave3_B.StreamFormattedRead1_o5 = 0.0F;
    heli_q8_oppgave3_B.StreamFormattedRead1_o6 = 0.0F;
    heli_q8_oppgave3_B.StreamFormattedRead1_o7 = 0.0F;
    heli_q8_oppgave3_B.UnitDelay = 0.0F;
    heli_q8_oppgave3_B.UnitDelay_g = 0.0F;
    heli_q8_oppgave3_B.UnitDelay_gs = 0.0F;
    heli_q8_oppgave3_B.UnitDelay_m = 0.0F;
    heli_q8_oppgave3_B.UnitDelay_d = 0.0F;
    heli_q8_oppgave3_B.UnitDelay_c = 0.0F;
  }

  /* parameters */
  heli_q8_oppgave3_M->defaultParam = ((real_T *)&heli_q8_oppgave3_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_oppgave3_X;
    heli_q8_oppgave3_M->contStates = (x);
    (void) memset((void *)&heli_q8_oppgave3_X, 0,
                  sizeof(X_heli_q8_oppgave3_T));
  }

  /* states (dwork) */
  heli_q8_oppgave3_M->dwork = ((void *) &heli_q8_oppgave3_DW);
  (void) memset((void *)&heli_q8_oppgave3_DW, 0,
                sizeof(DW_heli_q8_oppgave3_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_oppgave3_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_oppgave3_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_oppgave3_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_oppgave3_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_oppgave3_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_oppgave3_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_oppgave3_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_oppgave3_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_oppgave3_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_oppgave3_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_oppgave3_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_oppgave3_DW.HILWriteAnalog_Buffer[1] = 0.0;
  heli_q8_oppgave3_DW.UnitDelay_DSTATE = 0.0F;
  heli_q8_oppgave3_DW.UnitDelay_DSTATE_p = 0.0F;
  heli_q8_oppgave3_DW.UnitDelay_DSTATE_j = 0.0F;
  heli_q8_oppgave3_DW.UnitDelay_DSTATE_a = 0.0F;
  heli_q8_oppgave3_DW.UnitDelay_DSTATE_pf = 0.0F;
  heli_q8_oppgave3_DW.UnitDelay_DSTATE_g = 0.0F;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_oppgave3_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_oppgave3_M->Sizes.numContStates = (13);/* Number of continuous states */
  heli_q8_oppgave3_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  heli_q8_oppgave3_M->Sizes.numY = (0);/* Number of model outputs */
  heli_q8_oppgave3_M->Sizes.numU = (0);/* Number of model inputs */
  heli_q8_oppgave3_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_oppgave3_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_oppgave3_M->Sizes.numBlocks = (137);/* Number of blocks */
  heli_q8_oppgave3_M->Sizes.numBlockIO = (53);/* Number of block outputs */
  heli_q8_oppgave3_M->Sizes.numBlockPrms = (545);/* Sum of parameter "widths" */
  return heli_q8_oppgave3_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

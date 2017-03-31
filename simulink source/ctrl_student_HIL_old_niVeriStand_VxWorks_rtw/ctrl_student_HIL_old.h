/*
 * ctrl_student_HIL_old.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL_old".
 *
 * Model version              : 1.470
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Mar 31 12:51:42 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_student_HIL_old_h_
#define RTW_HEADER_ctrl_student_HIL_old_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_student_HIL_old_COMMON_INCLUDES_
# define ctrl_student_HIL_old_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_student_HIL_old_COMMON_INCLUDES_ */

#include "ctrl_student_HIL_old_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ctrl_student_HIL_old_rtModel   RT_MODEL_ctrl_student_HIL_old_T

/* Block signals for system '<S12>/MATLAB Function' */
typedef struct {
  real_T y[9];                         /* '<S12>/MATLAB Function' */
} B_MATLABFunction_ctrl_student_T;

/* Block signals (auto storage) */
typedef struct {
  real_T L2_continuous;                /* '<S7>/L2_continuous' */
  real_T PosYRight;                    /* '<S7>/PosYRight' */
  real_T PosXRight;                    /* '<S7>/PosXRight' */
  real_T R2_continuous;                /* '<S7>/R2_continuous' */
  real_T x_in;                         /* '<Root>/x_in' */
  real_T y_in;                         /* '<Root>/y_in' */
  real_T PosXLeft;                     /* '<S7>/PosXLeft' */
  real_T PosYLeft;                     /* '<S7>/PosYLeft' */
  real_T L1;                           /* '<S7>/L1' */
  real_T R1;                           /* '<S7>/R1' */
  real_T ArrowDown;                    /* '<S7>/ArrowDown' */
  real_T ArrowUp;                      /* '<S7>/ArrowUp' */
  real_T ArrowLeft;                    /* '<S7>/ArrowLeft' */
  real_T ArrowRight;                   /* '<S7>/ArrowRight' */
  real_T Integrator[3];                /* '<Root>/Integrator' */
  real_T Memory;                       /* '<S9>/Memory' */
  real_T psi_in;                       /* '<Root>/psi_in' */
  real_T r_in;                         /* '<Root>/r_in' */
  real_T u_in;                         /* '<Root>/u_in' */
  real_T v_in;                         /* '<Root>/v_in' */
  real_T N_power;                      /* '<Root>/N_power' */
  real_T N_power_H;                    /* '<Root>/N_power_H' */
  real_T Samp_freq;                    /* '<Root>/Samp_freq' */
  real_T dead;                         /* '<S5>/dead' */
  real_T counter;                      /* '<S20>/counter' */
  real_T WhiteNoise;                   /* '<S26>/White Noise' */
  real_T WhiteNoise_e;                 /* '<S27>/White Noise' */
  real_T WhiteNoise_m;                 /* '<S25>/White Noise' */
  real_T TmpSignalConversionAtetaaaInpor[3];
  real_T Hold[3];                      /* '<S21>/Hold' */
  real_T Enable_noise;                 /* '<Root>/Enable_noise' */
  real_T Product[3];                   /* '<Root>/Product' */
  real_T Memory4[3];                   /* '<S1>/Memory4' */
  real_T Memory5[3];                   /* '<S1>/Memory5' */
  real_T Memory2;                      /* '<S1>/Memory2' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Integrator1;                  /* '<S1>/Integrator1' */
  real_T Memory_p[11];                 /* '<S1>/Memory' */
  real_T Kd1;                          /* '<S12>/Kd1' */
  real_T Kd2;                          /* '<S12>/Kd2' */
  real_T Kd3;                          /* '<S12>/Kd3' */
  real_T Sum_k[3];                     /* '<Root>/Sum' */
  real_T Memory3[3];                   /* '<S1>/Memory3' */
  real_T Memory1[3];                   /* '<S1>/Memory1' */
  real_T Integrator_e[3];              /* '<S3>/Integrator' */
  real_T Memory_d[10];                 /* '<S8>/Memory' */
  real_T Memory1_l[10];                /* '<S8>/Memory1' */
  real_T Sum1[3];                      /* '<S3>/Sum1' */
  real_T Integrator1_c[3];             /* '<S3>/Integrator1' */
  real_T L12;                          /* '<S29>/L12' */
  real_T L11;                          /* '<S29>/L11' */
  real_T L13;                          /* '<S29>/L13' */
  real_T L21;                          /* '<S30>/L21' */
  real_T L22;                          /* '<S30>/L22' */
  real_T L23;                          /* '<S30>/L23' */
  real_T L31;                          /* '<S31>/L31' */
  real_T L32;                          /* '<S31>/L32' */
  real_T L33;                          /* '<S31>/L33' */
  real_T Product3[3];                  /* '<S3>/Product3' */
  real_T Sum_j[3];                     /* '<S3>/Sum' */
  real_T invM[3];                      /* '<S3>/inv(M)' */
  real_T switch_signal;                /* '<S9>/Switch_function' */
  real_T vecx[10];                     /* '<S8>/MATLAB Function' */
  real_T vecy[10];                     /* '<S8>/MATLAB Function' */
  real_T d;                            /* '<S8>/MATLAB Function' */
  real_T u_BT;                         /* '<S7>/Thrust allocation' */
  real_T u_VSP;                        /* '<S7>/Thrust allocation' */
  real_T alpha_VSP;                    /* '<S7>/Thrust allocation' */
  real_T omega_VSP;                    /* '<S7>/Thrust allocation' */
  real_T output[3];                    /* '<S21>/MATLAB Function1' */
  real_T count;                        /* '<S20>/MATLAB Function' */
  real_T z1[3];                        /* '<S1>/z1//z2' */
  real_T z2[3];                        /* '<S1>/z1//z2' */
  real_T s_dot1;                       /* '<S1>/update law' */
  real_T i;                            /* '<S1>/update law' */
  real_T signal[11];                   /* '<S1>/signal switch ' */
  real_T U_ref_l;                      /* '<S1>/inputs' */
  real_T D1[3];                        /* '<S1>/controller' */
  real_T z11[3];                       /* '<S1>/controller' */
  real_T ma[3];                        /* '<S1>/controller' */
  real_T Kdz[3];                       /* '<S1>/controller' */
  real_T eta_v[11];                    /* '<S1>/Ellipsoidal path' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction_an;/* '<S31>/MATLAB Function' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction_hb;/* '<S30>/MATLAB Function' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction_a;/* '<S29>/MATLAB Function' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction_h;/* '<S12>/MATLAB Function' */
} B_ctrl_student_HIL_old_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T L2_continuous_DWORK1;         /* '<S7>/L2_continuous' */
  real_T PosYRight_DWORK1;             /* '<S7>/PosYRight' */
  real_T PosXRight_DWORK1;             /* '<S7>/PosXRight' */
  real_T R2_continuous_DWORK1;         /* '<S7>/R2_continuous' */
  real_T x_in_DWORK1;                  /* '<Root>/x_in' */
  real_T y_in_DWORK1;                  /* '<Root>/y_in' */
  real_T u_BT_DWORK1;                  /* '<S7>/u_BT' */
  real_T u_VSP1_DWORK1;                /* '<S7>/u_VSP1' */
  real_T u_VSP2_DWORK1;                /* '<S7>/u_VSP2' */
  real_T alpha_VSP1_DWORK1;            /* '<S7>/alpha_VSP1' */
  real_T alpha_VSP2_DWORK1;            /* '<S7>/alpha_VSP2' */
  real_T PosXLeft_DWORK1;              /* '<S7>/PosXLeft' */
  real_T omega_VSP1_DWORK1;            /* '<S7>/omega_VSP1' */
  real_T PosYLeft_DWORK1;              /* '<S7>/PosYLeft' */
  real_T omega_VSP2_DWORK1;            /* '<S7>/omega_VSP2' */
  real_T L1_DWORK1;                    /* '<S7>/L1' */
  real_T R1_DWORK1;                    /* '<S7>/R1' */
  real_T ArrowDown_DWORK1;             /* '<S7>/ArrowDown' */
  real_T ArrowUp_DWORK1;               /* '<S7>/ArrowUp' */
  real_T ArrowLeft_DWORK1;             /* '<S7>/ArrowLeft' */
  real_T ArrowRight_DWORK1;            /* '<S7>/ArrowRight' */
  real_T imu_DWORK1[3];                /* '<Root>/imu' */
  real_T Memory_PreviousInput;         /* '<S9>/Memory' */
  real_T guidance_switch_DWORK1;       /* '<Root>/guidance_switch' */
  real_T psi_in_DWORK1;                /* '<Root>/psi_in' */
  real_T r_in_DWORK1;                  /* '<Root>/r_in' */
  real_T u_in_DWORK1;                  /* '<Root>/u_in' */
  real_T v_in_DWORK1;                  /* '<Root>/v_in' */
  real_T N_power_DWORK1;               /* '<Root>/N_power' */
  real_T N_power_H_DWORK1;             /* '<Root>/N_power_H' */
  real_T Samp_freq_DWORK1;             /* '<Root>/Samp_freq' */
  real_T dead_DWORK1;                  /* '<S5>/dead' */
  real_T counter_PreviousInput;        /* '<S20>/counter' */
  real_T NextOutput;                   /* '<S26>/White Noise' */
  real_T NextOutput_c;                 /* '<S27>/White Noise' */
  real_T NextOutput_p;                 /* '<S25>/White Noise' */
  real_T Hold_PreviousInput[3];        /* '<S21>/Hold' */
  real_T Enable_noise_DWORK1;          /* '<Root>/Enable_noise' */
  real_T psi_noise_DWORK1;             /* '<S6>/psi_noise' */
  real_T x_noise_DWORK1;               /* '<S6>/x_noise' */
  real_T y_noise_DWORK1;               /* '<S6>/y_noise' */
  real_T Memory4_PreviousInput[3];     /* '<S1>/Memory4' */
  real_T Memory5_PreviousInput[3];     /* '<S1>/Memory5' */
  real_T Memory2_PreviousInput;        /* '<S1>/Memory2' */
  real_T Memory_PreviousInput_l[11];   /* '<S1>/Memory' */
  real_T Kd1_DWORK1;                   /* '<S12>/Kd1' */
  real_T Kd2_DWORK1;                   /* '<S12>/Kd2' */
  real_T Kd3_DWORK1;                   /* '<S12>/Kd3' */
  real_T X_d_DWORK1;                   /* '<S10>/X_d' */
  real_T N_d_DWORK1;                   /* '<S10>/N_d' */
  real_T Y_d_DWORK1;                   /* '<S10>/Y_d' */
  real_T psi_0_DWORK1;                 /* '<S10>/psi_0 ' */
  real_T x_0_DWORK1;                   /* '<S10>/x_0' */
  real_T y_0_DWORK1;                   /* '<S10>/y_0' */
  real_T integratorresetmodel_DWORK1;  /* '<S10>/integrator reset model' */
  real_T s_DWORK1;                     /* '<S1>/s' */
  real_T D_DWORK1[3];                  /* '<S1>/D' */
  real_T z1_DWORK1[3];                 /* '<S1>/z1' */
  real_T ma_DWORK1[3];                 /* '<S1>/ma' */
  real_T kdz_DWORK1[3];                /* '<S1>/kdz' */
  real_T etaaa_DWORK1[3];              /* '<S1>/etaaa' */
  real_T etav_DWORK1[11];              /* '<S1>/etav' */
  real_T uref_DWORK1;                  /* '<S1>/uref ' */
  real_T Memory3_PreviousInput[3];     /* '<S1>/Memory3' */
  real_T Memory1_PreviousInput[3];     /* '<S1>/Memory1' */
  real_T sdot_DWORK1;                  /* '<S1>/sdot' */
  real_T i_DWORK1;                     /* '<S1>/i' */
  real_T Memory_PreviousInput_p[10];   /* '<S8>/Memory' */
  real_T Memory1_PreviousInput_m[10];  /* '<S8>/Memory1' */
  real_T x_bar_DWORK1;                 /* '<S33>/x_bar' */
  real_T y_bar_DWORK1;                 /* '<S33>/y_bar' */
  real_T psi_bar_DWORK1;               /* '<S33>/psi_bar' */
  real_T psi_hat_DWORK1;               /* '<S34>/psi_hat' */
  real_T x_hat_DWORK1;                 /* '<S34>/x_hat' */
  real_T y_hat_DWORK1;                 /* '<S34>/y_hat' */
  real_T r_hat_DWORK1;                 /* '<S35>/r_hat' */
  real_T u_hat_DWORK1;                 /* '<S35>/u_hat' */
  real_T v_hat_DWORK1;                 /* '<S35>/v_hat' */
  real_T L12_DWORK1;                   /* '<S29>/L12' */
  real_T L11_DWORK1;                   /* '<S29>/L11' */
  real_T L13_DWORK1;                   /* '<S29>/L13' */
  real_T L21_DWORK1;                   /* '<S30>/L21' */
  real_T L22_DWORK1;                   /* '<S30>/L22' */
  real_T L23_DWORK1;                   /* '<S30>/L23' */
  real_T L31_DWORK1;                   /* '<S31>/L31' */
  real_T L32_DWORK1;                   /* '<S31>/L32' */
  real_T L33_DWORK1;                   /* '<S31>/L33' */
  real_T lost_DWORK1;                  /* '<S8>/lost' */
  int32_T NIVeriStandSignalProbe_DWORK2;/* '<Root>/NIVeriStandSignalProbe' */
  uint32_T RandSeed;                   /* '<S26>/White Noise' */
  uint32_T RandSeed_j;                 /* '<S27>/White Noise' */
  uint32_T RandSeed_c;                 /* '<S25>/White Noise' */
  uint8_T L2_continuous_DWORK2[21];    /* '<S7>/L2_continuous' */
  uint8_T PosYRight_DWORK2[21];        /* '<S7>/PosYRight' */
  uint8_T PosXRight_DWORK2[21];        /* '<S7>/PosXRight' */
  uint8_T R2_continuous_DWORK2[21];    /* '<S7>/R2_continuous' */
  uint8_T x_in_DWORK2[21];             /* '<Root>/x_in' */
  uint8_T y_in_DWORK2[21];             /* '<Root>/y_in' */
  uint8_T u_BT_DWORK2[21];             /* '<S7>/u_BT' */
  uint8_T u_VSP1_DWORK2[21];           /* '<S7>/u_VSP1' */
  uint8_T u_VSP2_DWORK2[21];           /* '<S7>/u_VSP2' */
  uint8_T alpha_VSP1_DWORK2[21];       /* '<S7>/alpha_VSP1' */
  uint8_T alpha_VSP2_DWORK2[21];       /* '<S7>/alpha_VSP2' */
  uint8_T PosXLeft_DWORK2[21];         /* '<S7>/PosXLeft' */
  uint8_T omega_VSP1_DWORK2[21];       /* '<S7>/omega_VSP1' */
  uint8_T PosYLeft_DWORK2[21];         /* '<S7>/PosYLeft' */
  uint8_T omega_VSP2_DWORK2[21];       /* '<S7>/omega_VSP2' */
  uint8_T L1_DWORK2[21];               /* '<S7>/L1' */
  uint8_T R1_DWORK2[21];               /* '<S7>/R1' */
  uint8_T ArrowDown_DWORK2[21];        /* '<S7>/ArrowDown' */
  uint8_T ArrowUp_DWORK2[21];          /* '<S7>/ArrowUp' */
  uint8_T ArrowLeft_DWORK2[21];        /* '<S7>/ArrowLeft' */
  uint8_T ArrowRight_DWORK2[21];       /* '<S7>/ArrowRight' */
  uint8_T imu_DWORK2[21];              /* '<Root>/imu' */
  uint8_T guidance_switch_DWORK2[21];  /* '<Root>/guidance_switch' */
  uint8_T psi_in_DWORK2[21];           /* '<Root>/psi_in' */
  uint8_T r_in_DWORK2[21];             /* '<Root>/r_in' */
  uint8_T u_in_DWORK2[21];             /* '<Root>/u_in' */
  uint8_T v_in_DWORK2[21];             /* '<Root>/v_in' */
  uint8_T N_power_DWORK2[21];          /* '<Root>/N_power' */
  uint8_T N_power_H_DWORK2[21];        /* '<Root>/N_power_H' */
  uint8_T Samp_freq_DWORK2[21];        /* '<Root>/Samp_freq' */
  uint8_T dead_DWORK2[21];             /* '<S5>/dead' */
  uint8_T Enable_noise_DWORK2[21];     /* '<Root>/Enable_noise' */
  uint8_T psi_noise_DWORK2[21];        /* '<S6>/psi_noise' */
  uint8_T x_noise_DWORK2[21];          /* '<S6>/x_noise' */
  uint8_T y_noise_DWORK2[21];          /* '<S6>/y_noise' */
  uint8_T Kd1_DWORK2[21];              /* '<S12>/Kd1' */
  uint8_T Kd2_DWORK2[21];              /* '<S12>/Kd2' */
  uint8_T Kd3_DWORK2[21];              /* '<S12>/Kd3' */
  uint8_T X_d_DWORK2[21];              /* '<S10>/X_d' */
  uint8_T N_d_DWORK2[21];              /* '<S10>/N_d' */
  uint8_T Y_d_DWORK2[21];              /* '<S10>/Y_d' */
  uint8_T psi_0_DWORK2[21];            /* '<S10>/psi_0 ' */
  uint8_T x_0_DWORK2[21];              /* '<S10>/x_0' */
  uint8_T y_0_DWORK2[21];              /* '<S10>/y_0' */
  uint8_T integratorresetmodel_DWORK2[21];/* '<S10>/integrator reset model' */
  uint8_T s_DWORK2[21];                /* '<S1>/s' */
  uint8_T D_DWORK2[21];                /* '<S1>/D' */
  uint8_T z1_DWORK2[21];               /* '<S1>/z1' */
  uint8_T ma_DWORK2[21];               /* '<S1>/ma' */
  uint8_T kdz_DWORK2[21];              /* '<S1>/kdz' */
  uint8_T etaaa_DWORK2[21];            /* '<S1>/etaaa' */
  uint8_T etav_DWORK2[21];             /* '<S1>/etav' */
  uint8_T uref_DWORK2[21];             /* '<S1>/uref ' */
  uint8_T sdot_DWORK2[21];             /* '<S1>/sdot' */
  uint8_T i_DWORK2[21];                /* '<S1>/i' */
  uint8_T x_bar_DWORK2[21];            /* '<S33>/x_bar' */
  uint8_T y_bar_DWORK2[21];            /* '<S33>/y_bar' */
  uint8_T psi_bar_DWORK2[21];          /* '<S33>/psi_bar' */
  uint8_T psi_hat_DWORK2[21];          /* '<S34>/psi_hat' */
  uint8_T x_hat_DWORK2[21];            /* '<S34>/x_hat' */
  uint8_T y_hat_DWORK2[21];            /* '<S34>/y_hat' */
  uint8_T r_hat_DWORK2[21];            /* '<S35>/r_hat' */
  uint8_T u_hat_DWORK2[21];            /* '<S35>/u_hat' */
  uint8_T v_hat_DWORK2[21];            /* '<S35>/v_hat' */
  uint8_T L12_DWORK2[21];              /* '<S29>/L12' */
  uint8_T L11_DWORK2[21];              /* '<S29>/L11' */
  uint8_T L13_DWORK2[21];              /* '<S29>/L13' */
  uint8_T L21_DWORK2[21];              /* '<S30>/L21' */
  uint8_T L22_DWORK2[21];              /* '<S30>/L22' */
  uint8_T L23_DWORK2[21];              /* '<S30>/L23' */
  uint8_T L31_DWORK2[21];              /* '<S31>/L31' */
  uint8_T L32_DWORK2[21];              /* '<S31>/L32' */
  uint8_T L33_DWORK2[21];              /* '<S31>/L33' */
  uint8_T lost_DWORK2[21];             /* '<S8>/lost' */
  uint8_T NIVeriStandSignalProbe_DWORK1[21];/* '<Root>/NIVeriStandSignalProbe' */
  uint8_T NIVeriStandSignalProbe_DWORK3[64];/* '<Root>/NIVeriStandSignalProbe' */
} DW_ctrl_student_HIL_old_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S3>/Integrator2' */
  real_T Integrator_CSTATE_h[3];       /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE_k[3];      /* '<S3>/Integrator1' */
} X_ctrl_student_HIL_old_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S3>/Integrator2' */
  real_T Integrator_CSTATE_h[3];       /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE_k[3];      /* '<S3>/Integrator1' */
} XDot_ctrl_student_HIL_old_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<Root>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator2_CSTATE[3];     /* '<S3>/Integrator2' */
  boolean_T Integrator_CSTATE_h[3];    /* '<S3>/Integrator' */
  boolean_T Integrator1_CSTATE_k[3];   /* '<S3>/Integrator1' */
} XDis_ctrl_student_HIL_old_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<Root>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S1>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S3>/Integrator2' */
  ZCSigState Integrator_Reset_ZCE_b;   /* '<S3>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE_n;  /* '<S3>/Integrator1' */
} PrevZCX_ctrl_student_HIL_old_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_student_HIL_old_B
#define BlockIO                        B_ctrl_student_HIL_old_T
#define rtX                            ctrl_student_HIL_old_X
#define ContinuousStates               X_ctrl_student_HIL_old_T
#define rtXdot                         ctrl_student_HIL_old_XDot
#define StateDerivatives               XDot_ctrl_student_HIL_old_T
#define tXdis                          ctrl_student_HIL_old_XDis
#define StateDisabled                  XDis_ctrl_student_HIL_old_T
#define rtP                            ctrl_student_HIL_old_P
#define Parameters                     P_ctrl_student_HIL_old_T
#define rtDWork                        ctrl_student_HIL_old_DW
#define D_Work                         DW_ctrl_student_HIL_old_T
#define rtPrevZCSigState               ctrl_student_HIL_old_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_student_HIL_old_T

/* Parameters (auto storage) */
struct P_ctrl_student_HIL_old_T_ {
  real_T L2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T L2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T L2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T L2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T L2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T L2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  real_T PosYRight_P1;                 /* Expression: width
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosYRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosYRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosYRight_P4;                 /* Expression: stime
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosYRight_P5;                 /* Expression: stype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosYRight_P6;                 /* Expression: btype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  real_T PosXRight_P1;                 /* Expression: width
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosXRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosXRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosXRight_P4;                 /* Expression: stime
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosXRight_P5;                 /* Expression: stype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T PosXRight_P6;                 /* Expression: btype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  real_T R2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T R2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T R2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T R2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T R2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T R2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  real_T Gain_Gain;                    /* Expression: -.5
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T x_in_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T x_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T x_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T x_in_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T x_in_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T x_in_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T y_in_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T y_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T y_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T y_in_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T y_in_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T y_in_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T True_Value;                   /* Expression: 1
                                        * Referenced by: '<S7>/True'
                                        */
  real_T u_BT_P1;                      /* Expression: width
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_BT_P2;                      /* Expression: dtype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_BT_P3;                      /* Expression: portnum
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_BT_P4;                      /* Expression: stime
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_BT_P5;                      /* Expression: stype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_BT_P6;                      /* Expression: btype
                                        * Referenced by: '<S7>/u_BT'
                                        */
  real_T u_VSP1_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP1_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP1_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP1_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP1'
                                        */
  real_T u_VSP2_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T u_VSP2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T u_VSP2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T u_VSP2_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T u_VSP2_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T u_VSP2_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/u_VSP2'
                                        */
  real_T alpha_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP1'
                                        */
  real_T alpha_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S7>/alpha_VSP2'
                                        */
  real_T PosXLeft_P1;                  /* Expression: width
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosXLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosXLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosXLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosXLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T PosXLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  real_T omega_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP1'
                                        */
  real_T PosYLeft_P1;                  /* Expression: width
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T PosYLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T PosYLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T PosYLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T PosYLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T PosYLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  real_T omega_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S7>/omega_VSP2'
                                        */
  real_T L1_P1;                        /* Expression: width
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T L1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T L1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T L1_P4;                        /* Expression: stime
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T L1_P5;                        /* Expression: stype
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T L1_P6;                        /* Expression: btype
                                        * Referenced by: '<S7>/L1'
                                        */
  real_T R1_P1;                        /* Expression: width
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T R1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T R1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T R1_P4;                        /* Expression: stime
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T R1_P5;                        /* Expression: stype
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T R1_P6;                        /* Expression: btype
                                        * Referenced by: '<S7>/R1'
                                        */
  real_T ArrowDown_P1;                 /* Expression: width
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowDown_P2;                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowDown_P3;                 /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowDown_P4;                 /* Expression: stime
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowDown_P5;                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowDown_P6;                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  real_T ArrowUp_P1;                   /* Expression: width
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowUp_P2;                   /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowUp_P3;                   /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowUp_P4;                   /* Expression: stime
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowUp_P5;                   /* Expression: stype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowUp_P6;                   /* Expression: btype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  real_T ArrowLeft_P1;                 /* Expression: width
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowLeft_P2;                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowLeft_P3;                 /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowLeft_P4;                 /* Expression: stime
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowLeft_P5;                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowLeft_P6;                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  real_T ArrowRight_P1;                /* Expression: width
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T ArrowRight_P2;                /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T ArrowRight_P3;                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T ArrowRight_P4;                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T ArrowRight_P5;                /* Expression: stype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T ArrowRight_P6;                /* Expression: btype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T imu_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/imu'
                                        */
  real_T imu_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/imu'
                                        */
  real_T imu_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/imu'
                                        */
  real_T imu_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/imu'
                                        */
  real_T imu_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/imu'
                                        */
  real_T imu_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/imu'
                                        */
  real_T Memory_X0;                    /* Expression: 3
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T guidance_switch_P1;           /* Expression: width
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  real_T guidance_switch_P2;           /* Expression: dtype
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  real_T guidance_switch_P3;           /* Expression: portnum
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  real_T guidance_switch_P4;           /* Expression: stime
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  real_T guidance_switch_P5;           /* Expression: stype
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  real_T guidance_switch_P6;           /* Expression: btype
                                        * Referenced by: '<Root>/guidance_switch'
                                        */
  real_T psi_in_P1;                    /* Expression: width
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T psi_in_P2;                    /* Expression: dtype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T psi_in_P3;                    /* Expression: portnum
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T psi_in_P4;                    /* Expression: stime
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T psi_in_P5;                    /* Expression: stype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T psi_in_P6;                    /* Expression: btype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T r_in_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T r_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T r_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T r_in_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T r_in_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T r_in_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T u_in_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T u_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T u_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T u_in_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T u_in_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T u_in_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T v_in_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T v_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T v_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T v_in_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T v_in_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T v_in_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T N_power_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/N_power'
                                        */
  real_T N_power_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/N_power'
                                        */
  real_T N_power_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/N_power'
                                        */
  real_T N_power_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/N_power'
                                        */
  real_T N_power_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/N_power'
                                        */
  real_T N_power_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/N_power'
                                        */
  real_T N_power_H_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  real_T N_power_H_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  real_T N_power_H_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  real_T N_power_H_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  real_T N_power_H_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  real_T N_power_H_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/N_power_H'
                                        */
  real_T Samp_freq_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  real_T Samp_freq_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  real_T Samp_freq_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  real_T Samp_freq_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  real_T Samp_freq_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  real_T Samp_freq_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/Samp_freq'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T dead_P1;                      /* Expression: width
                                        * Referenced by: '<S5>/dead'
                                        */
  real_T dead_P2;                      /* Expression: dtype
                                        * Referenced by: '<S5>/dead'
                                        */
  real_T dead_P3;                      /* Expression: portnum
                                        * Referenced by: '<S5>/dead'
                                        */
  real_T dead_P4;                      /* Expression: stime
                                        * Referenced by: '<S5>/dead'
                                        */
  real_T dead_P5;                      /* Expression: stype
                                        * Referenced by: '<S5>/dead'
                                        */
  real_T dead_P6;                      /* Expression: btype
                                        * Referenced by: '<S5>/dead'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Stepsize_Value;               /* Expression: 0.01
                                        * Referenced by: '<S2>/Step size'
                                        */
  real_T counter_X0;                   /* Expression: 0
                                        * Referenced by: '<S20>/counter'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S26>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S26>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: 9024
                                        * Referenced by: '<S26>/White Noise'
                                        */
  real_T WhiteNoise_Mean_h;            /* Expression: 0
                                        * Referenced by: '<S27>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_d;          /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S27>/White Noise'
                                        */
  real_T WhiteNoise_Seed_b;            /* Expression: 123
                                        * Referenced by: '<S27>/White Noise'
                                        */
  real_T WhiteNoise_Mean_f;            /* Expression: 0
                                        * Referenced by: '<S25>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_g;          /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S25>/White Noise'
                                        */
  real_T WhiteNoise_Seed_l;            /* Expression: 9025
                                        * Referenced by: '<S25>/White Noise'
                                        */
  real_T Hold_X0;                      /* Expression: 0
                                        * Referenced by: '<S21>/Hold'
                                        */
  real_T Enable_noise_P1;              /* Expression: width
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  real_T Enable_noise_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  real_T Enable_noise_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  real_T Enable_noise_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  real_T Enable_noise_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  real_T Enable_noise_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/Enable_noise'
                                        */
  real_T psi_noise_P1;                 /* Expression: width
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  real_T psi_noise_P2;                 /* Expression: dtype
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  real_T psi_noise_P3;                 /* Expression: portnum
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  real_T psi_noise_P4;                 /* Expression: stime
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  real_T psi_noise_P5;                 /* Expression: stype
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  real_T psi_noise_P6;                 /* Expression: btype
                                        * Referenced by: '<S6>/psi_noise'
                                        */
  real_T x_noise_P1;                   /* Expression: width
                                        * Referenced by: '<S6>/x_noise'
                                        */
  real_T x_noise_P2;                   /* Expression: dtype
                                        * Referenced by: '<S6>/x_noise'
                                        */
  real_T x_noise_P3;                   /* Expression: portnum
                                        * Referenced by: '<S6>/x_noise'
                                        */
  real_T x_noise_P4;                   /* Expression: stime
                                        * Referenced by: '<S6>/x_noise'
                                        */
  real_T x_noise_P5;                   /* Expression: stype
                                        * Referenced by: '<S6>/x_noise'
                                        */
  real_T x_noise_P6;                   /* Expression: btype
                                        * Referenced by: '<S6>/x_noise'
                                        */
  real_T y_noise_P1;                   /* Expression: width
                                        * Referenced by: '<S6>/y_noise'
                                        */
  real_T y_noise_P2;                   /* Expression: dtype
                                        * Referenced by: '<S6>/y_noise'
                                        */
  real_T y_noise_P3;                   /* Expression: portnum
                                        * Referenced by: '<S6>/y_noise'
                                        */
  real_T y_noise_P4;                   /* Expression: stime
                                        * Referenced by: '<S6>/y_noise'
                                        */
  real_T y_noise_P5;                   /* Expression: stype
                                        * Referenced by: '<S6>/y_noise'
                                        */
  real_T y_noise_P6;                   /* Expression: btype
                                        * Referenced by: '<S6>/y_noise'
                                        */
  real_T Memory4_X0[3];                /* Expression: [0;0;0]
                                        * Referenced by: '<S1>/Memory4'
                                        */
  real_T Memory5_X0[3];                /* Expression: [0;0;0]
                                        * Referenced by: '<S1>/Memory5'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  real_T Gain_Gain_l[3];               /* Expression: [1 1 1]
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Memory_X0_j;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Kd1_P1;                       /* Expression: width
                                        * Referenced by: '<S12>/Kd1'
                                        */
  real_T Kd1_P2;                       /* Expression: dtype
                                        * Referenced by: '<S12>/Kd1'
                                        */
  real_T Kd1_P3;                       /* Expression: portnum
                                        * Referenced by: '<S12>/Kd1'
                                        */
  real_T Kd1_P4;                       /* Expression: stime
                                        * Referenced by: '<S12>/Kd1'
                                        */
  real_T Kd1_P5;                       /* Expression: stype
                                        * Referenced by: '<S12>/Kd1'
                                        */
  real_T Kd1_P6;                       /* Expression: btype
                                        * Referenced by: '<S12>/Kd1'
                                        */
  real_T Kd2_P1;                       /* Expression: width
                                        * Referenced by: '<S12>/Kd2'
                                        */
  real_T Kd2_P2;                       /* Expression: dtype
                                        * Referenced by: '<S12>/Kd2'
                                        */
  real_T Kd2_P3;                       /* Expression: portnum
                                        * Referenced by: '<S12>/Kd2'
                                        */
  real_T Kd2_P4;                       /* Expression: stime
                                        * Referenced by: '<S12>/Kd2'
                                        */
  real_T Kd2_P5;                       /* Expression: stype
                                        * Referenced by: '<S12>/Kd2'
                                        */
  real_T Kd2_P6;                       /* Expression: btype
                                        * Referenced by: '<S12>/Kd2'
                                        */
  real_T Kd3_P1;                       /* Expression: width
                                        * Referenced by: '<S12>/Kd3'
                                        */
  real_T Kd3_P2;                       /* Expression: dtype
                                        * Referenced by: '<S12>/Kd3'
                                        */
  real_T Kd3_P3;                       /* Expression: portnum
                                        * Referenced by: '<S12>/Kd3'
                                        */
  real_T Kd3_P4;                       /* Expression: stime
                                        * Referenced by: '<S12>/Kd3'
                                        */
  real_T Kd3_P5;                       /* Expression: stype
                                        * Referenced by: '<S12>/Kd3'
                                        */
  real_T Kd3_P6;                       /* Expression: btype
                                        * Referenced by: '<S12>/Kd3'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  real_T X_d_P1;                       /* Expression: width
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T X_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T X_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T X_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T X_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T X_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T N_d_P1;                       /* Expression: width
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T N_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T N_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T N_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T N_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T N_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T Y_d_P1;                       /* Expression: width
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Y_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Y_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Y_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Y_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Y_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T psi_0_P1;                     /* Expression: width
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T psi_0_P2;                     /* Expression: dtype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T psi_0_P3;                     /* Expression: portnum
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T psi_0_P4;                     /* Expression: stime
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T psi_0_P5;                     /* Expression: stype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T psi_0_P6;                     /* Expression: btype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T x_0_P1;                       /* Expression: width
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T x_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T x_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T x_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T x_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T x_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T Constant1_Value_h;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T y_0_P1;                       /* Expression: width
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T y_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T y_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T y_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T y_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T y_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T integratorresetmodel_P1;      /* Expression: width
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T integratorresetmodel_P2;      /* Expression: dtype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T integratorresetmodel_P3;      /* Expression: portnum
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T integratorresetmodel_P4;      /* Expression: stime
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T integratorresetmodel_P5;      /* Expression: stype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T integratorresetmodel_P6;      /* Expression: btype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T s_P1;                         /* Expression: width
                                        * Referenced by: '<S1>/s'
                                        */
  real_T s_P2;                         /* Expression: dtype
                                        * Referenced by: '<S1>/s'
                                        */
  real_T s_P3;                         /* Expression: portnum
                                        * Referenced by: '<S1>/s'
                                        */
  real_T s_P4;                         /* Expression: stime
                                        * Referenced by: '<S1>/s'
                                        */
  real_T s_P5;                         /* Expression: stype
                                        * Referenced by: '<S1>/s'
                                        */
  real_T s_P6;                         /* Expression: btype
                                        * Referenced by: '<S1>/s'
                                        */
  real_T D_P1;                         /* Expression: width
                                        * Referenced by: '<S1>/D'
                                        */
  real_T D_P2;                         /* Expression: dtype
                                        * Referenced by: '<S1>/D'
                                        */
  real_T D_P3;                         /* Expression: portnum
                                        * Referenced by: '<S1>/D'
                                        */
  real_T D_P4;                         /* Expression: stime
                                        * Referenced by: '<S1>/D'
                                        */
  real_T D_P5;                         /* Expression: stype
                                        * Referenced by: '<S1>/D'
                                        */
  real_T D_P6;                         /* Expression: btype
                                        * Referenced by: '<S1>/D'
                                        */
  real_T z1_P1;                        /* Expression: width
                                        * Referenced by: '<S1>/z1'
                                        */
  real_T z1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S1>/z1'
                                        */
  real_T z1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S1>/z1'
                                        */
  real_T z1_P4;                        /* Expression: stime
                                        * Referenced by: '<S1>/z1'
                                        */
  real_T z1_P5;                        /* Expression: stype
                                        * Referenced by: '<S1>/z1'
                                        */
  real_T z1_P6;                        /* Expression: btype
                                        * Referenced by: '<S1>/z1'
                                        */
  real_T ma_P1;                        /* Expression: width
                                        * Referenced by: '<S1>/ma'
                                        */
  real_T ma_P2;                        /* Expression: dtype
                                        * Referenced by: '<S1>/ma'
                                        */
  real_T ma_P3;                        /* Expression: portnum
                                        * Referenced by: '<S1>/ma'
                                        */
  real_T ma_P4;                        /* Expression: stime
                                        * Referenced by: '<S1>/ma'
                                        */
  real_T ma_P5;                        /* Expression: stype
                                        * Referenced by: '<S1>/ma'
                                        */
  real_T ma_P6;                        /* Expression: btype
                                        * Referenced by: '<S1>/ma'
                                        */
  real_T kdz_P1;                       /* Expression: width
                                        * Referenced by: '<S1>/kdz'
                                        */
  real_T kdz_P2;                       /* Expression: dtype
                                        * Referenced by: '<S1>/kdz'
                                        */
  real_T kdz_P3;                       /* Expression: portnum
                                        * Referenced by: '<S1>/kdz'
                                        */
  real_T kdz_P4;                       /* Expression: stime
                                        * Referenced by: '<S1>/kdz'
                                        */
  real_T kdz_P5;                       /* Expression: stype
                                        * Referenced by: '<S1>/kdz'
                                        */
  real_T kdz_P6;                       /* Expression: btype
                                        * Referenced by: '<S1>/kdz'
                                        */
  real_T etaaa_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/etaaa'
                                        */
  real_T etaaa_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/etaaa'
                                        */
  real_T etaaa_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/etaaa'
                                        */
  real_T etaaa_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/etaaa'
                                        */
  real_T etaaa_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/etaaa'
                                        */
  real_T etaaa_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/etaaa'
                                        */
  real_T etav_P1;                      /* Expression: width
                                        * Referenced by: '<S1>/etav'
                                        */
  real_T etav_P2;                      /* Expression: dtype
                                        * Referenced by: '<S1>/etav'
                                        */
  real_T etav_P3;                      /* Expression: portnum
                                        * Referenced by: '<S1>/etav'
                                        */
  real_T etav_P4;                      /* Expression: stime
                                        * Referenced by: '<S1>/etav'
                                        */
  real_T etav_P5;                      /* Expression: stype
                                        * Referenced by: '<S1>/etav'
                                        */
  real_T etav_P6;                      /* Expression: btype
                                        * Referenced by: '<S1>/etav'
                                        */
  real_T uref_P1;                      /* Expression: width
                                        * Referenced by: '<S1>/uref '
                                        */
  real_T uref_P2;                      /* Expression: dtype
                                        * Referenced by: '<S1>/uref '
                                        */
  real_T uref_P3;                      /* Expression: portnum
                                        * Referenced by: '<S1>/uref '
                                        */
  real_T uref_P4;                      /* Expression: stime
                                        * Referenced by: '<S1>/uref '
                                        */
  real_T uref_P5;                      /* Expression: stype
                                        * Referenced by: '<S1>/uref '
                                        */
  real_T uref_P6;                      /* Expression: btype
                                        * Referenced by: '<S1>/uref '
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory3'
                                        */
  real_T Memory1_X0[3];                /* Expression: [0 0 0]
                                        * Referenced by: '<S1>/Memory1'
                                        */
  real_T sdot_P1;                      /* Expression: width
                                        * Referenced by: '<S1>/sdot'
                                        */
  real_T sdot_P2;                      /* Expression: dtype
                                        * Referenced by: '<S1>/sdot'
                                        */
  real_T sdot_P3;                      /* Expression: portnum
                                        * Referenced by: '<S1>/sdot'
                                        */
  real_T sdot_P4;                      /* Expression: stime
                                        * Referenced by: '<S1>/sdot'
                                        */
  real_T sdot_P5;                      /* Expression: stype
                                        * Referenced by: '<S1>/sdot'
                                        */
  real_T sdot_P6;                      /* Expression: btype
                                        * Referenced by: '<S1>/sdot'
                                        */
  real_T i_P1;                         /* Expression: width
                                        * Referenced by: '<S1>/i'
                                        */
  real_T i_P2;                         /* Expression: dtype
                                        * Referenced by: '<S1>/i'
                                        */
  real_T i_P3;                         /* Expression: portnum
                                        * Referenced by: '<S1>/i'
                                        */
  real_T i_P4;                         /* Expression: stime
                                        * Referenced by: '<S1>/i'
                                        */
  real_T i_P5;                         /* Expression: stype
                                        * Referenced by: '<S1>/i'
                                        */
  real_T i_P6;                         /* Expression: btype
                                        * Referenced by: '<S1>/i'
                                        */
  real_T Integrator_IC_d;              /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Memory_X0_d[10];              /* Expression: [0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S8>/Memory'
                                        */
  real_T Memory1_X0_e[10];             /* Expression: [0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S8>/Memory1'
                                        */
  real_T x_bar_P1;                     /* Expression: width
                                        * Referenced by: '<S33>/x_bar'
                                        */
  real_T x_bar_P2;                     /* Expression: dtype
                                        * Referenced by: '<S33>/x_bar'
                                        */
  real_T x_bar_P3;                     /* Expression: portnum
                                        * Referenced by: '<S33>/x_bar'
                                        */
  real_T x_bar_P4;                     /* Expression: stime
                                        * Referenced by: '<S33>/x_bar'
                                        */
  real_T x_bar_P5;                     /* Expression: stype
                                        * Referenced by: '<S33>/x_bar'
                                        */
  real_T x_bar_P6;                     /* Expression: btype
                                        * Referenced by: '<S33>/x_bar'
                                        */
  real_T y_bar_P1;                     /* Expression: width
                                        * Referenced by: '<S33>/y_bar'
                                        */
  real_T y_bar_P2;                     /* Expression: dtype
                                        * Referenced by: '<S33>/y_bar'
                                        */
  real_T y_bar_P3;                     /* Expression: portnum
                                        * Referenced by: '<S33>/y_bar'
                                        */
  real_T y_bar_P4;                     /* Expression: stime
                                        * Referenced by: '<S33>/y_bar'
                                        */
  real_T y_bar_P5;                     /* Expression: stype
                                        * Referenced by: '<S33>/y_bar'
                                        */
  real_T y_bar_P6;                     /* Expression: btype
                                        * Referenced by: '<S33>/y_bar'
                                        */
  real_T psi_bar_P1;                   /* Expression: width
                                        * Referenced by: '<S33>/psi_bar'
                                        */
  real_T psi_bar_P2;                   /* Expression: dtype
                                        * Referenced by: '<S33>/psi_bar'
                                        */
  real_T psi_bar_P3;                   /* Expression: portnum
                                        * Referenced by: '<S33>/psi_bar'
                                        */
  real_T psi_bar_P4;                   /* Expression: stime
                                        * Referenced by: '<S33>/psi_bar'
                                        */
  real_T psi_bar_P5;                   /* Expression: stype
                                        * Referenced by: '<S33>/psi_bar'
                                        */
  real_T psi_bar_P6;                   /* Expression: btype
                                        * Referenced by: '<S33>/psi_bar'
                                        */
  real_T psi_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S34>/psi_hat'
                                        */
  real_T psi_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S34>/psi_hat'
                                        */
  real_T psi_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S34>/psi_hat'
                                        */
  real_T psi_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S34>/psi_hat'
                                        */
  real_T psi_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S34>/psi_hat'
                                        */
  real_T psi_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S34>/psi_hat'
                                        */
  real_T x_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S34>/x_hat'
                                        */
  real_T x_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S34>/x_hat'
                                        */
  real_T x_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S34>/x_hat'
                                        */
  real_T x_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S34>/x_hat'
                                        */
  real_T x_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S34>/x_hat'
                                        */
  real_T x_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S34>/x_hat'
                                        */
  real_T y_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S34>/y_hat'
                                        */
  real_T y_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S34>/y_hat'
                                        */
  real_T y_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S34>/y_hat'
                                        */
  real_T y_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S34>/y_hat'
                                        */
  real_T y_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S34>/y_hat'
                                        */
  real_T y_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S34>/y_hat'
                                        */
  real_T Integrator1_IC_p;             /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  real_T r_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S35>/r_hat'
                                        */
  real_T r_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S35>/r_hat'
                                        */
  real_T r_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S35>/r_hat'
                                        */
  real_T r_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S35>/r_hat'
                                        */
  real_T r_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S35>/r_hat'
                                        */
  real_T r_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S35>/r_hat'
                                        */
  real_T u_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S35>/u_hat'
                                        */
  real_T u_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S35>/u_hat'
                                        */
  real_T u_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S35>/u_hat'
                                        */
  real_T u_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S35>/u_hat'
                                        */
  real_T u_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S35>/u_hat'
                                        */
  real_T u_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S35>/u_hat'
                                        */
  real_T v_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S35>/v_hat'
                                        */
  real_T v_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S35>/v_hat'
                                        */
  real_T v_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S35>/v_hat'
                                        */
  real_T v_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S35>/v_hat'
                                        */
  real_T v_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S35>/v_hat'
                                        */
  real_T v_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S35>/v_hat'
                                        */
  real_T L12_P1;                       /* Expression: width
                                        * Referenced by: '<S29>/L12'
                                        */
  real_T L12_P2;                       /* Expression: dtype
                                        * Referenced by: '<S29>/L12'
                                        */
  real_T L12_P3;                       /* Expression: portnum
                                        * Referenced by: '<S29>/L12'
                                        */
  real_T L12_P4;                       /* Expression: stime
                                        * Referenced by: '<S29>/L12'
                                        */
  real_T L12_P5;                       /* Expression: stype
                                        * Referenced by: '<S29>/L12'
                                        */
  real_T L12_P6;                       /* Expression: btype
                                        * Referenced by: '<S29>/L12'
                                        */
  real_T L11_P1;                       /* Expression: width
                                        * Referenced by: '<S29>/L11'
                                        */
  real_T L11_P2;                       /* Expression: dtype
                                        * Referenced by: '<S29>/L11'
                                        */
  real_T L11_P3;                       /* Expression: portnum
                                        * Referenced by: '<S29>/L11'
                                        */
  real_T L11_P4;                       /* Expression: stime
                                        * Referenced by: '<S29>/L11'
                                        */
  real_T L11_P5;                       /* Expression: stype
                                        * Referenced by: '<S29>/L11'
                                        */
  real_T L11_P6;                       /* Expression: btype
                                        * Referenced by: '<S29>/L11'
                                        */
  real_T L13_P1;                       /* Expression: width
                                        * Referenced by: '<S29>/L13'
                                        */
  real_T L13_P2;                       /* Expression: dtype
                                        * Referenced by: '<S29>/L13'
                                        */
  real_T L13_P3;                       /* Expression: portnum
                                        * Referenced by: '<S29>/L13'
                                        */
  real_T L13_P4;                       /* Expression: stime
                                        * Referenced by: '<S29>/L13'
                                        */
  real_T L13_P5;                       /* Expression: stype
                                        * Referenced by: '<S29>/L13'
                                        */
  real_T L13_P6;                       /* Expression: btype
                                        * Referenced by: '<S29>/L13'
                                        */
  real_T L21_P1;                       /* Expression: width
                                        * Referenced by: '<S30>/L21'
                                        */
  real_T L21_P2;                       /* Expression: dtype
                                        * Referenced by: '<S30>/L21'
                                        */
  real_T L21_P3;                       /* Expression: portnum
                                        * Referenced by: '<S30>/L21'
                                        */
  real_T L21_P4;                       /* Expression: stime
                                        * Referenced by: '<S30>/L21'
                                        */
  real_T L21_P5;                       /* Expression: stype
                                        * Referenced by: '<S30>/L21'
                                        */
  real_T L21_P6;                       /* Expression: btype
                                        * Referenced by: '<S30>/L21'
                                        */
  real_T L22_P1;                       /* Expression: width
                                        * Referenced by: '<S30>/L22'
                                        */
  real_T L22_P2;                       /* Expression: dtype
                                        * Referenced by: '<S30>/L22'
                                        */
  real_T L22_P3;                       /* Expression: portnum
                                        * Referenced by: '<S30>/L22'
                                        */
  real_T L22_P4;                       /* Expression: stime
                                        * Referenced by: '<S30>/L22'
                                        */
  real_T L22_P5;                       /* Expression: stype
                                        * Referenced by: '<S30>/L22'
                                        */
  real_T L22_P6;                       /* Expression: btype
                                        * Referenced by: '<S30>/L22'
                                        */
  real_T L23_P1;                       /* Expression: width
                                        * Referenced by: '<S30>/L23'
                                        */
  real_T L23_P2;                       /* Expression: dtype
                                        * Referenced by: '<S30>/L23'
                                        */
  real_T L23_P3;                       /* Expression: portnum
                                        * Referenced by: '<S30>/L23'
                                        */
  real_T L23_P4;                       /* Expression: stime
                                        * Referenced by: '<S30>/L23'
                                        */
  real_T L23_P5;                       /* Expression: stype
                                        * Referenced by: '<S30>/L23'
                                        */
  real_T L23_P6;                       /* Expression: btype
                                        * Referenced by: '<S30>/L23'
                                        */
  real_T L31_P1;                       /* Expression: width
                                        * Referenced by: '<S31>/L31'
                                        */
  real_T L31_P2;                       /* Expression: dtype
                                        * Referenced by: '<S31>/L31'
                                        */
  real_T L31_P3;                       /* Expression: portnum
                                        * Referenced by: '<S31>/L31'
                                        */
  real_T L31_P4;                       /* Expression: stime
                                        * Referenced by: '<S31>/L31'
                                        */
  real_T L31_P5;                       /* Expression: stype
                                        * Referenced by: '<S31>/L31'
                                        */
  real_T L31_P6;                       /* Expression: btype
                                        * Referenced by: '<S31>/L31'
                                        */
  real_T L32_P1;                       /* Expression: width
                                        * Referenced by: '<S31>/L32'
                                        */
  real_T L32_P2;                       /* Expression: dtype
                                        * Referenced by: '<S31>/L32'
                                        */
  real_T L32_P3;                       /* Expression: portnum
                                        * Referenced by: '<S31>/L32'
                                        */
  real_T L32_P4;                       /* Expression: stime
                                        * Referenced by: '<S31>/L32'
                                        */
  real_T L32_P5;                       /* Expression: stype
                                        * Referenced by: '<S31>/L32'
                                        */
  real_T L32_P6;                       /* Expression: btype
                                        * Referenced by: '<S31>/L32'
                                        */
  real_T L33_P1;                       /* Expression: width
                                        * Referenced by: '<S31>/L33'
                                        */
  real_T L33_P2;                       /* Expression: dtype
                                        * Referenced by: '<S31>/L33'
                                        */
  real_T L33_P3;                       /* Expression: portnum
                                        * Referenced by: '<S31>/L33'
                                        */
  real_T L33_P4;                       /* Expression: stime
                                        * Referenced by: '<S31>/L33'
                                        */
  real_T L33_P5;                       /* Expression: stype
                                        * Referenced by: '<S31>/L33'
                                        */
  real_T L33_P6;                       /* Expression: btype
                                        * Referenced by: '<S31>/L33'
                                        */
  real_T invM_Gain[9];                 /* Expression: inv([14.79 0 0;
                                          0 14.79 14.79*0.0375;
                                          0 14.79*0.0375 1.76])
                                        * Referenced by: '<S3>/inv(M)'
                                        */
  real_T lost_P1;                      /* Expression: width
                                        * Referenced by: '<S8>/lost'
                                        */
  real_T lost_P2;                      /* Expression: dtype
                                        * Referenced by: '<S8>/lost'
                                        */
  real_T lost_P3;                      /* Expression: portnum
                                        * Referenced by: '<S8>/lost'
                                        */
  real_T lost_P4;                      /* Expression: stime
                                        * Referenced by: '<S8>/lost'
                                        */
  real_T lost_P5;                      /* Expression: stype
                                        * Referenced by: '<S8>/lost'
                                        */
  real_T lost_P6;                      /* Expression: btype
                                        * Referenced by: '<S8>/lost'
                                        */
  real_T NIVeriStandSignalProbe_P1;    /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_student_HIL_old_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[13];
    real_T odeF[4][13];
    ODE4_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ctrl_student_HIL_old_T ctrl_student_HIL_old_P;

/* Block signals (auto storage) */
extern B_ctrl_student_HIL_old_T ctrl_student_HIL_old_B;

/* Continuous states (auto storage) */
extern X_ctrl_student_HIL_old_T ctrl_student_HIL_old_X;

/* Block states (auto storage) */
extern DW_ctrl_student_HIL_old_T ctrl_student_HIL_old_DW;

/* Model entry point functions */
extern void ctrl_student_HIL_old_initialize(void);
extern void ctrl_student_HIL_old_output(void);
extern void ctrl_student_HIL_old_update(void);
extern void ctrl_student_HIL_old_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_student_HIL_old_rtModel *ctrl_student_HIL_old(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_student_HIL_old_T *const ctrl_student_HIL_old_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ctrl_student_HIL_old'
 * '<S1>'   : 'ctrl_student_HIL_old/DP-system'
 * '<S2>'   : 'ctrl_student_HIL_old/Noise generator'
 * '<S3>'   : 'ctrl_student_HIL_old/Observer'
 * '<S4>'   : 'ctrl_student_HIL_old/Switch joystick  and DP-system'
 * '<S5>'   : 'ctrl_student_HIL_old/dead rec  switch'
 * '<S6>'   : 'ctrl_student_HIL_old/eta_noise_ut'
 * '<S7>'   : 'ctrl_student_HIL_old/joystick'
 * '<S8>'   : 'ctrl_student_HIL_old/signal dropout check '
 * '<S9>'   : 'ctrl_student_HIL_old/switch'
 * '<S10>'  : 'ctrl_student_HIL_old/tau to CSE mocell (only use for HIL testing)'
 * '<S11>'  : 'ctrl_student_HIL_old/DP-system/Ellipsoidal path'
 * '<S12>'  : 'ctrl_student_HIL_old/DP-system/Kd'
 * '<S13>'  : 'ctrl_student_HIL_old/DP-system/Straight -line '
 * '<S14>'  : 'ctrl_student_HIL_old/DP-system/controller'
 * '<S15>'  : 'ctrl_student_HIL_old/DP-system/inputs'
 * '<S16>'  : 'ctrl_student_HIL_old/DP-system/signal switch '
 * '<S17>'  : 'ctrl_student_HIL_old/DP-system/update law'
 * '<S18>'  : 'ctrl_student_HIL_old/DP-system/z1//z2'
 * '<S19>'  : 'ctrl_student_HIL_old/DP-system/Kd/MATLAB Function'
 * '<S20>'  : 'ctrl_student_HIL_old/Noise generator/Downsample	signal'
 * '<S21>'  : 'ctrl_student_HIL_old/Noise generator/Sample & hold'
 * '<S22>'  : 'ctrl_student_HIL_old/Noise generator/noise generator'
 * '<S23>'  : 'ctrl_student_HIL_old/Noise generator/Downsample	signal/MATLAB Function'
 * '<S24>'  : 'ctrl_student_HIL_old/Noise generator/Sample & hold/MATLAB Function1'
 * '<S25>'  : 'ctrl_student_HIL_old/Noise generator/noise generator/Band-limited white noise psi'
 * '<S26>'  : 'ctrl_student_HIL_old/Noise generator/noise generator/Band-limited white noise x'
 * '<S27>'  : 'ctrl_student_HIL_old/Noise generator/noise generator/Band-limited white noise y'
 * '<S28>'  : 'ctrl_student_HIL_old/Observer/D'
 * '<S29>'  : 'ctrl_student_HIL_old/Observer/L1'
 * '<S30>'  : 'ctrl_student_HIL_old/Observer/L2'
 * '<S31>'  : 'ctrl_student_HIL_old/Observer/L3'
 * '<S32>'  : 'ctrl_student_HIL_old/Observer/Rotation matrix'
 * '<S33>'  : 'ctrl_student_HIL_old/Observer/eta_bar_ut'
 * '<S34>'  : 'ctrl_student_HIL_old/Observer/eta_hat_ut'
 * '<S35>'  : 'ctrl_student_HIL_old/Observer/nu_hat_ut'
 * '<S36>'  : 'ctrl_student_HIL_old/Observer/L1/MATLAB Function'
 * '<S37>'  : 'ctrl_student_HIL_old/Observer/L2/MATLAB Function'
 * '<S38>'  : 'ctrl_student_HIL_old/Observer/L3/MATLAB Function'
 * '<S39>'  : 'ctrl_student_HIL_old/joystick/MATLAB Function'
 * '<S40>'  : 'ctrl_student_HIL_old/joystick/Thrust allocation'
 * '<S41>'  : 'ctrl_student_HIL_old/signal dropout check /MATLAB Function'
 * '<S42>'  : 'ctrl_student_HIL_old/switch/Switch_function'
 */
#endif                                 /* RTW_HEADER_ctrl_student_HIL_old_h_ */

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#define NI_SIT_PARAMS
#ifdef NI_ROOTMODEL_ctrl_student_HIL_old
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

P_ctrl_student_HIL_old_T rtParameter[NUMST+!TID01EQ];
P_ctrl_student_HIL_old_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

P_ctrl_student_HIL_old_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

extern int tid;
extern P_ctrl_student_HIL_old_T* param_lookup[NUMST][2];

#else

extern P_ctrl_student_HIL_old_T rtParameter[];

#endif
#endif

#ifdef MULTITASKING
#define ctrl_student_HIL_old_P         (*param_lookup[tid][READSIDE])
#else
#define ctrl_student_HIL_old_P         rtParameter[READSIDE]
#endif
#endif
#endif
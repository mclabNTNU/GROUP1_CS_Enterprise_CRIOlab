/*
 * ctrl_student_HIL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.173
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Mar 31 08:59:54 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_student_HIL_h_
#define RTW_HEADER_ctrl_student_HIL_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_student_HIL_COMMON_INCLUDES_
# define ctrl_student_HIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_student_HIL_COMMON_INCLUDES_ */

#include "ctrl_student_HIL_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

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
#define ctrl_student_HIL_rtModel       RT_MODEL_ctrl_student_HIL_T

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
  real_T x;                            /* '<Root>/x' */
  real_T y;                            /* '<Root>/y' */
  real_T Product[3];                   /* '<S7>/Product' */
  real_T PosXLeft;                     /* '<S7>/PosXLeft' */
  real_T PosYLeft;                     /* '<S7>/PosYLeft' */
  real_T L1;                           /* '<S7>/L1' */
  real_T R1;                           /* '<S7>/R1' */
  real_T ArrowDown;                    /* '<S7>/ArrowDown' */
  real_T ArrowUp;                      /* '<S7>/ArrowUp' */
  real_T ArrowLeft;                    /* '<S7>/ArrowLeft' */
  real_T ArrowRight;                   /* '<S7>/ArrowRight' */
  real_T Memory;                       /* '<S9>/Memory' */
  real_T dead;                         /* '<S5>/dead' */
  real_T counter;                      /* '<S21>/counter' */
  real_T Samp_freq;                    /* '<Root>/Samp_freq' */
  real_T N_power;                      /* '<Root>/N_power' */
  real_T WhiteNoise;                   /* '<S27>/White Noise' */
  real_T WhiteNoise_n;                 /* '<S28>/White Noise' */
  real_T N_power_H;                    /* '<Root>/N_power_H' */
  real_T WhiteNoise_d;                 /* '<S26>/White Noise' */
  real_T psi;                          /* '<Root>/psi' */
  real_T Hold[3];                      /* '<S22>/Hold' */
  real_T Enable_noise;                 /* '<Root>/Enable_noise' */
  real_T Memory_f[20];                 /* '<S8>/Memory' */
  real_T Memory1[20];                  /* '<S8>/Memory1' */
  real_T Memory3;                      /* '<S8>/Memory3' */
  real_T Memory2;                      /* '<S8>/Memory2' */
  real_T Product_i[3];                 /* '<Root>/Product' */
  real_T Memory4[3];                   /* '<S1>/Memory4' */
  real_T Memory5[3];                   /* '<S1>/Memory5' */
  real_T Memory2_e;                    /* '<S1>/Memory2' */
  real_T Integrator[3];                /* '<S3>/Integrator' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Integrator1;                  /* '<S1>/Integrator1' */
  real_T Memory6[2];                   /* '<S1>/Memory6' */
  real_T Memory_k[11];                 /* '<S1>/Memory' */
  real_T Integrator1_k[3];             /* '<S3>/Integrator1' */
  real_T Kd1;                          /* '<S12>/Kd1' */
  real_T Kd2;                          /* '<S12>/Kd2' */
  real_T Kd3;                          /* '<S12>/Kd3' */
  real_T Integrator2[3];               /* '<S3>/Integrator2' */
  real_T Sum_c[3];                     /* '<Root>/Sum' */
  real_T TmpSignalConversionAttauJInport[3];
  real_T Memory3_c[3];                 /* '<S1>/Memory3' */
  real_T Memory1_n[3];                 /* '<S1>/Memory1' */
  real_T Sum1[3];                      /* '<S3>/Sum1' */
  real_T L12;                          /* '<S30>/L12' */
  real_T L11;                          /* '<S30>/L11' */
  real_T L13;                          /* '<S30>/L13' */
  real_T L21;                          /* '<S31>/L21' */
  real_T L22;                          /* '<S31>/L22' */
  real_T L23;                          /* '<S31>/L23' */
  real_T L31;                          /* '<S32>/L31' */
  real_T L32;                          /* '<S32>/L32' */
  real_T L33;                          /* '<S32>/L33' */
  real_T Product3[3];                  /* '<S3>/Product3' */
  real_T Sum_b[3];                     /* '<S3>/Sum' */
  real_T invM[3];                      /* '<S3>/inv(M)' */
  real_T u_BT;                         /* '<S10>/Full thrust allocation' */
  real_T u_VSP;                        /* '<S10>/Full thrust allocation' */
  real_T alpha_VSP;                    /* '<S10>/Full thrust allocation' */
  real_T omega_VSP;                    /* '<S10>/Full thrust allocation' */
  real_T switch_signal;                /* '<S9>/Switch_function' */
  real_T vecx[20];                     /* '<S8>/MATLAB Function' */
  real_T vecy[20];                     /* '<S8>/MATLAB Function' */
  real_T d;                            /* '<S8>/MATLAB Function' */
  real_T s1;                           /* '<S8>/MATLAB Function' */
  real_T s2;                           /* '<S8>/MATLAB Function' */
  real_T u_BT_d;                       /* '<S7>/Thrust allocation' */
  real_T u_VSP_p;                      /* '<S7>/Thrust allocation' */
  real_T alpha_VSP_b;                  /* '<S7>/Thrust allocation' */
  real_T omega_VSP_h;                  /* '<S7>/Thrust allocation' */
  real_T output[3];                    /* '<S22>/MATLAB Function1' */
  real_T count;                        /* '<S21>/MATLAB Function' */
  real_T z1[3];                        /* '<S1>/z1-jjz2' */
  real_T z2[3];                        /* '<S1>/z1-jjz2' */
  real_T s_dot1;                       /* '<S1>/update law' */
  real_T i;                            /* '<S1>/update law' */
  real_T signal[11];                   /* '<S1>/signal switch ' */
  real_T eta_0[2];                     /* '<S1>/inputs' */
  real_T eta_d[2];                     /* '<S1>/inputs' */
  real_T U_ref_l;                      /* '<S1>/inputs' */
  real_T D1[3];                        /* '<S1>/controller' */
  real_T z11[3];                       /* '<S1>/controller' */
  real_T ma[3];                        /* '<S1>/controller' */
  real_T Kdz[3];                       /* '<S1>/controller' */
  real_T temp[2];                      /* '<S1>/MATLAB Function' */
  real_T eta_v[11];                    /* '<S1>/Ellipsoidal path' */
  boolean_T fault;                     /* '<S47>/control limit checking' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction_o;/* '<S32>/MATLAB Function' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction_fv;/* '<S31>/MATLAB Function' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction_l;/* '<S30>/MATLAB Function' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction_m;/* '<S12>/MATLAB Function' */
} B_ctrl_student_HIL_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T L2_continuous_DWORK1;         /* '<S7>/L2_continuous' */
  real_T PosYRight_DWORK1;             /* '<S7>/PosYRight' */
  real_T PosXRight_DWORK1;             /* '<S7>/PosXRight' */
  real_T R2_continuous_DWORK1;         /* '<S7>/R2_continuous' */
  real_T x_DWORK1;                     /* '<Root>/x' */
  real_T y_DWORK1;                     /* '<Root>/y' */
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
  real_T posX_DWORK1;                  /* '<S7>/posX' */
  real_T R1_DWORK1;                    /* '<S7>/R1' */
  real_T ArrowDown_DWORK1;             /* '<S7>/ArrowDown' */
  real_T posY_DWORK1;                  /* '<S7>/posY' */
  real_T ArrowUp_DWORK1;               /* '<S7>/ArrowUp' */
  real_T ArrowLeft_DWORK1;             /* '<S7>/ArrowLeft' */
  real_T ArrowRight_DWORK1;            /* '<S7>/ArrowRight' */
  real_T Memory_PreviousInput;         /* '<S9>/Memory' */
  real_T guidance_switch_DWORK1;       /* '<Root>/guidance_switch' */
  real_T dead_DWORK1;                  /* '<S5>/dead' */
  real_T counter_PreviousInput;        /* '<S21>/counter' */
  real_T Samp_freq_DWORK1;             /* '<Root>/Samp_freq' */
  real_T N_power_DWORK1;               /* '<Root>/N_power' */
  real_T NextOutput;                   /* '<S27>/White Noise' */
  real_T NextOutput_n;                 /* '<S28>/White Noise' */
  real_T N_power_H_DWORK1;             /* '<Root>/N_power_H' */
  real_T NextOutput_i;                 /* '<S26>/White Noise' */
  real_T psi_DWORK1;                   /* '<Root>/psi' */
  real_T Hold_PreviousInput[3];        /* '<S22>/Hold' */
  real_T Enable_noise_DWORK1;          /* '<Root>/Enable_noise' */
  real_T Memory_PreviousInput_c[20];   /* '<S8>/Memory' */
  real_T Memory1_PreviousInput[20];    /* '<S8>/Memory1' */
  real_T Memory3_PreviousInput;        /* '<S8>/Memory3' */
  real_T Memory2_PreviousInput;        /* '<S8>/Memory2' */
  real_T Memory4_PreviousInput[3];     /* '<S1>/Memory4' */
  real_T Memory5_PreviousInput[3];     /* '<S1>/Memory5' */
  real_T Memory2_PreviousInput_k;      /* '<S1>/Memory2' */
  real_T Memory6_PreviousInput[2];     /* '<S1>/Memory6' */
  real_T Memory_PreviousInput_l[11];   /* '<S1>/Memory' */
  real_T Kd1_DWORK1;                   /* '<S12>/Kd1' */
  real_T Kd2_DWORK1;                   /* '<S12>/Kd2' */
  real_T Kd3_DWORK1;                   /* '<S12>/Kd3' */
  real_T tauut_DWORK1[3];              /* '<Root>/tauut' */
  real_T tauJ_DWORK1[3];               /* '<Root>/tauJ' */
  real_T psi_noise_DWORK1;             /* '<S6>/psi_noise' */
  real_T x_noise_DWORK1;               /* '<S6>/x_noise' */
  real_T y_noise_DWORK1;               /* '<S6>/y_noise' */
  real_T controlinputuexceedsbounds_DWOR;/* '<S47>/control input u exceeds bounds' */
  real_T alpha_VSP2_DWORK1_l;          /* '<S49>/alpha_VSP2' */
  real_T omega_VSP1_DWORK1_k;          /* '<S49>/omega_VSP1' */
  real_T omega_VSP2_DWORK1_c;          /* '<S49>/omega_VSP2' */
  real_T alpha_VSP1_DWORK1_h;          /* '<S49>/alpha_VSP1' */
  real_T u_BT_DWORK1_j;                /* '<S49>/u_BT' */
  real_T u_VSP1_DWORK1_p;              /* '<S49>/u_VSP1' */
  real_T u_VSP2_DWORK1_e;              /* '<S49>/u_VSP2' */
  real_T s_DWORK1;                     /* '<S1>/s' */
  real_T D_DWORK1[3];                  /* '<S1>/D' */
  real_T z1_DWORK1[3];                 /* '<S1>/z1' */
  real_T ma_DWORK1[3];                 /* '<S1>/ma' */
  real_T kdz_DWORK1[3];                /* '<S1>/kdz' */
  real_T etaaa_DWORK1[3];              /* '<S1>/etaaa' */
  real_T etav_DWORK1[11];              /* '<S1>/etav' */
  real_T uref_DWORK1;                  /* '<S1>/uref ' */
  real_T Memory3_PreviousInput_n[3];   /* '<S1>/Memory3' */
  real_T Memory1_PreviousInput_i[3];   /* '<S1>/Memory1' */
  real_T sdot_DWORK1;                  /* '<S1>/sdot' */
  real_T i_DWORK1;                     /* '<S1>/i' */
  real_T eta_d_DWORK1[2];              /* '<S1>/eta_d' */
  real_T eta_0_DWORK1[2];              /* '<S1>/eta_0' */
  real_T bias_1_DWORK1;                /* '<S34>/bias_1' */
  real_T bias_2_DWORK1;                /* '<S34>/bias_2' */
  real_T bias_3_DWORK1;                /* '<S34>/bias_3' */
  real_T x_bar_DWORK1;                 /* '<S35>/x_bar' */
  real_T y_bar_DWORK1;                 /* '<S35>/y_bar' */
  real_T psi_bar_DWORK1;               /* '<S35>/psi_bar' */
  real_T psi_hat_DWORK1;               /* '<S36>/psi_hat' */
  real_T x_hat_DWORK1;                 /* '<S36>/x_hat' */
  real_T y_hat_DWORK1;                 /* '<S36>/y_hat' */
  real_T r_hat_DWORK1;                 /* '<S37>/r_hat' */
  real_T u_hat_DWORK1;                 /* '<S37>/u_hat' */
  real_T v_hat_DWORK1;                 /* '<S37>/v_hat' */
  real_T L12_DWORK1;                   /* '<S30>/L12' */
  real_T L11_DWORK1;                   /* '<S30>/L11' */
  real_T L13_DWORK1;                   /* '<S30>/L13' */
  real_T L21_DWORK1;                   /* '<S31>/L21' */
  real_T L22_DWORK1;                   /* '<S31>/L22' */
  real_T L23_DWORK1;                   /* '<S31>/L23' */
  real_T L31_DWORK1;                   /* '<S32>/L31' */
  real_T L32_DWORK1;                   /* '<S32>/L32' */
  real_T L33_DWORK1;                   /* '<S32>/L33' */
  real_T lost_DWORK1;                  /* '<S8>/lost' */
  real_T s1_DWORK1;                    /* '<S8>/s1' */
  real_T s2_DWORK1;                    /* '<S8>/s2' */
  int32_T NIVeriStandSignalProbe_DWORK2;/* '<Root>/NIVeriStandSignalProbe' */
  uint32_T RandSeed;                   /* '<S27>/White Noise' */
  uint32_T RandSeed_a;                 /* '<S28>/White Noise' */
  uint32_T RandSeed_i;                 /* '<S26>/White Noise' */
  uint8_T L2_continuous_DWORK2[17];    /* '<S7>/L2_continuous' */
  uint8_T PosYRight_DWORK2[17];        /* '<S7>/PosYRight' */
  uint8_T PosXRight_DWORK2[17];        /* '<S7>/PosXRight' */
  uint8_T R2_continuous_DWORK2[17];    /* '<S7>/R2_continuous' */
  uint8_T x_DWORK2[17];                /* '<Root>/x' */
  uint8_T y_DWORK2[17];                /* '<Root>/y' */
  uint8_T u_BT_DWORK2[17];             /* '<S7>/u_BT' */
  uint8_T u_VSP1_DWORK2[17];           /* '<S7>/u_VSP1' */
  uint8_T u_VSP2_DWORK2[17];           /* '<S7>/u_VSP2' */
  uint8_T alpha_VSP1_DWORK2[17];       /* '<S7>/alpha_VSP1' */
  uint8_T alpha_VSP2_DWORK2[17];       /* '<S7>/alpha_VSP2' */
  uint8_T PosXLeft_DWORK2[17];         /* '<S7>/PosXLeft' */
  uint8_T omega_VSP1_DWORK2[17];       /* '<S7>/omega_VSP1' */
  uint8_T PosYLeft_DWORK2[17];         /* '<S7>/PosYLeft' */
  uint8_T omega_VSP2_DWORK2[17];       /* '<S7>/omega_VSP2' */
  uint8_T L1_DWORK2[17];               /* '<S7>/L1' */
  uint8_T posX_DWORK2[17];             /* '<S7>/posX' */
  uint8_T R1_DWORK2[17];               /* '<S7>/R1' */
  uint8_T ArrowDown_DWORK2[17];        /* '<S7>/ArrowDown' */
  uint8_T posY_DWORK2[17];             /* '<S7>/posY' */
  uint8_T ArrowUp_DWORK2[17];          /* '<S7>/ArrowUp' */
  uint8_T ArrowLeft_DWORK2[17];        /* '<S7>/ArrowLeft' */
  uint8_T ArrowRight_DWORK2[17];       /* '<S7>/ArrowRight' */
  uint8_T guidance_switch_DWORK2[17];  /* '<Root>/guidance_switch' */
  uint8_T dead_DWORK2[17];             /* '<S5>/dead' */
  uint8_T Samp_freq_DWORK2[17];        /* '<Root>/Samp_freq' */
  uint8_T N_power_DWORK2[17];          /* '<Root>/N_power' */
  uint8_T N_power_H_DWORK2[17];        /* '<Root>/N_power_H' */
  uint8_T psi_DWORK2[17];              /* '<Root>/psi' */
  uint8_T Enable_noise_DWORK2[17];     /* '<Root>/Enable_noise' */
  uint8_T Kd1_DWORK2[17];              /* '<S12>/Kd1' */
  uint8_T Kd2_DWORK2[17];              /* '<S12>/Kd2' */
  uint8_T Kd3_DWORK2[17];              /* '<S12>/Kd3' */
  uint8_T tauut_DWORK2[17];            /* '<Root>/tauut' */
  uint8_T tauJ_DWORK2[17];             /* '<Root>/tauJ' */
  uint8_T psi_noise_DWORK2[17];        /* '<S6>/psi_noise' */
  uint8_T x_noise_DWORK2[17];          /* '<S6>/x_noise' */
  uint8_T y_noise_DWORK2[17];          /* '<S6>/y_noise' */
  uint8_T controlinputuexceedsbounds_DW_j[17];/* '<S47>/control input u exceeds bounds' */
  uint8_T alpha_VSP2_DWORK2_b[17];     /* '<S49>/alpha_VSP2' */
  uint8_T omega_VSP1_DWORK2_n[17];     /* '<S49>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2_k[17];     /* '<S49>/omega_VSP2' */
  uint8_T alpha_VSP1_DWORK2_k[17];     /* '<S49>/alpha_VSP1' */
  uint8_T u_BT_DWORK2_h[17];           /* '<S49>/u_BT' */
  uint8_T u_VSP1_DWORK2_g[17];         /* '<S49>/u_VSP1' */
  uint8_T u_VSP2_DWORK2_a[17];         /* '<S49>/u_VSP2' */
  uint8_T s_DWORK2[17];                /* '<S1>/s' */
  uint8_T D_DWORK2[17];                /* '<S1>/D' */
  uint8_T z1_DWORK2[17];               /* '<S1>/z1' */
  uint8_T ma_DWORK2[17];               /* '<S1>/ma' */
  uint8_T kdz_DWORK2[17];              /* '<S1>/kdz' */
  uint8_T etaaa_DWORK2[17];            /* '<S1>/etaaa' */
  uint8_T etav_DWORK2[17];             /* '<S1>/etav' */
  uint8_T uref_DWORK2[17];             /* '<S1>/uref ' */
  uint8_T sdot_DWORK2[17];             /* '<S1>/sdot' */
  uint8_T i_DWORK2[17];                /* '<S1>/i' */
  uint8_T eta_d_DWORK2[17];            /* '<S1>/eta_d' */
  uint8_T eta_0_DWORK2[17];            /* '<S1>/eta_0' */
  uint8_T bias_1_DWORK2[17];           /* '<S34>/bias_1' */
  uint8_T bias_2_DWORK2[17];           /* '<S34>/bias_2' */
  uint8_T bias_3_DWORK2[17];           /* '<S34>/bias_3' */
  uint8_T x_bar_DWORK2[17];            /* '<S35>/x_bar' */
  uint8_T y_bar_DWORK2[17];            /* '<S35>/y_bar' */
  uint8_T psi_bar_DWORK2[17];          /* '<S35>/psi_bar' */
  uint8_T psi_hat_DWORK2[17];          /* '<S36>/psi_hat' */
  uint8_T x_hat_DWORK2[17];            /* '<S36>/x_hat' */
  uint8_T y_hat_DWORK2[17];            /* '<S36>/y_hat' */
  uint8_T r_hat_DWORK2[17];            /* '<S37>/r_hat' */
  uint8_T u_hat_DWORK2[17];            /* '<S37>/u_hat' */
  uint8_T v_hat_DWORK2[17];            /* '<S37>/v_hat' */
  uint8_T L12_DWORK2[17];              /* '<S30>/L12' */
  uint8_T L11_DWORK2[17];              /* '<S30>/L11' */
  uint8_T L13_DWORK2[17];              /* '<S30>/L13' */
  uint8_T L21_DWORK2[17];              /* '<S31>/L21' */
  uint8_T L22_DWORK2[17];              /* '<S31>/L22' */
  uint8_T L23_DWORK2[17];              /* '<S31>/L23' */
  uint8_T L31_DWORK2[17];              /* '<S32>/L31' */
  uint8_T L32_DWORK2[17];              /* '<S32>/L32' */
  uint8_T L33_DWORK2[17];              /* '<S32>/L33' */
  uint8_T lost_DWORK2[17];             /* '<S8>/lost' */
  uint8_T s1_DWORK2[17];               /* '<S8>/s1' */
  uint8_T s2_DWORK2[17];               /* '<S8>/s2' */
  uint8_T NIVeriStandSignalProbe_DWORK1[17];/* '<Root>/NIVeriStandSignalProbe' */
  uint8_T NIVeriStandSignalProbe_DWORK3[60];/* '<Root>/NIVeriStandSignalProbe' */
} DW_ctrl_student_HIL_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator1_CSTATE_b[3];      /* '<S3>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S3>/Integrator2' */
} X_ctrl_student_HIL_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator1_CSTATE_b[3];      /* '<S3>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S3>/Integrator2' */
} XDot_ctrl_student_HIL_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S3>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator1_CSTATE_b[3];   /* '<S3>/Integrator1' */
  boolean_T Integrator2_CSTATE[3];     /* '<S3>/Integrator2' */
} XDis_ctrl_student_HIL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S3>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S1>/Integrator1' */
  ZCSigState Integrator1_Reset_ZCE_l;  /* '<S3>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S3>/Integrator2' */
} PrevZCX_ctrl_student_HIL_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_student_HIL_B
#define BlockIO                        B_ctrl_student_HIL_T
#define rtX                            ctrl_student_HIL_X
#define ContinuousStates               X_ctrl_student_HIL_T
#define rtXdot                         ctrl_student_HIL_XDot
#define StateDerivatives               XDot_ctrl_student_HIL_T
#define tXdis                          ctrl_student_HIL_XDis
#define StateDisabled                  XDis_ctrl_student_HIL_T
#define rtP                            ctrl_student_HIL_P
#define Parameters                     P_ctrl_student_HIL_T
#define rtDWork                        ctrl_student_HIL_DW
#define D_Work                         DW_ctrl_student_HIL_T
#define rtPrevZCSigState               ctrl_student_HIL_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_student_HIL_T

/* Parameters (auto storage) */
struct P_ctrl_student_HIL_T_ {
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
  real_T x_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1/1000
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T y_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: -1
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
  real_T posX_P1;                      /* Expression: width
                                        * Referenced by: '<S7>/posX'
                                        */
  real_T posX_P2;                      /* Expression: dtype
                                        * Referenced by: '<S7>/posX'
                                        */
  real_T posX_P3;                      /* Expression: portnum
                                        * Referenced by: '<S7>/posX'
                                        */
  real_T posX_P4;                      /* Expression: stime
                                        * Referenced by: '<S7>/posX'
                                        */
  real_T posX_P5;                      /* Expression: stype
                                        * Referenced by: '<S7>/posX'
                                        */
  real_T posX_P6;                      /* Expression: btype
                                        * Referenced by: '<S7>/posX'
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
  real_T posY_P1;                      /* Expression: width
                                        * Referenced by: '<S7>/posY'
                                        */
  real_T posY_P2;                      /* Expression: dtype
                                        * Referenced by: '<S7>/posY'
                                        */
  real_T posY_P3;                      /* Expression: portnum
                                        * Referenced by: '<S7>/posY'
                                        */
  real_T posY_P4;                      /* Expression: stime
                                        * Referenced by: '<S7>/posY'
                                        */
  real_T posY_P5;                      /* Expression: stype
                                        * Referenced by: '<S7>/posY'
                                        */
  real_T posY_P6;                      /* Expression: btype
                                        * Referenced by: '<S7>/posY'
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
                                        * Referenced by: '<S21>/counter'
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
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S27>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S27>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: 9024
                                        * Referenced by: '<S27>/White Noise'
                                        */
  real_T WhiteNoise_Mean_d;            /* Expression: 0
                                        * Referenced by: '<S28>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_f;          /* Computed Parameter: WhiteNoise_StdDev_f
                                        * Referenced by: '<S28>/White Noise'
                                        */
  real_T WhiteNoise_Seed_o;            /* Expression: 123
                                        * Referenced by: '<S28>/White Noise'
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
  real_T WhiteNoise_Mean_c;            /* Expression: 0
                                        * Referenced by: '<S26>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_p;          /* Computed Parameter: WhiteNoise_StdDev_p
                                        * Referenced by: '<S26>/White Noise'
                                        */
  real_T WhiteNoise_Seed_h;            /* Expression: 9025
                                        * Referenced by: '<S26>/White Noise'
                                        */
  real_T psi_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T Gain2_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Hold_X0;                      /* Expression: 0
                                        * Referenced by: '<S22>/Hold'
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
  real_T Memory_X0_g[20];              /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S8>/Memory'
                                        */
  real_T Memory1_X0[20];               /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S8>/Memory1'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S8>/Memory3'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S8>/Memory2'
                                        */
  real_T Memory4_X0[3];                /* Expression: [0;0;0]
                                        * Referenced by: '<S1>/Memory4'
                                        */
  real_T Memory5_X0[3];                /* Expression: [0;0;0]
                                        * Referenced by: '<S1>/Memory5'
                                        */
  real_T Memory2_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Gain_Gain_g[3];               /* Expression: [1 1 1]
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Memory6_X0[2];                /* Expression: [0 0]
                                        * Referenced by: '<S1>/Memory6'
                                        */
  real_T Memory_X0_d;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Integrator1_IC_l;             /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
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
  real_T Constant_Value_jx[3];         /* Expression: [0;0;0]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T tauut_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/tauut'
                                        */
  real_T tauut_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/tauut'
                                        */
  real_T tauut_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/tauut'
                                        */
  real_T tauut_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/tauut'
                                        */
  real_T tauut_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/tauut'
                                        */
  real_T tauut_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/tauut'
                                        */
  real_T tauJ_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/tauJ'
                                        */
  real_T tauJ_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/tauJ'
                                        */
  real_T tauJ_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/tauJ'
                                        */
  real_T tauJ_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/tauJ'
                                        */
  real_T tauJ_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/tauJ'
                                        */
  real_T tauJ_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/tauJ'
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
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T controlinputuexceedsbounds_P1;/* Expression: width
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P2;/* Expression: dtype
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P3;/* Expression: portnum
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P4;/* Expression: stime
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P5;/* Expression: stype
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  real_T controlinputuexceedsbounds_P6;/* Expression: btype
                                        * Referenced by: '<S47>/control input u exceeds bounds'
                                        */
  real_T alpha_VSP2_P1_g;              /* Expression: width
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2_e;              /* Expression: dtype
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3_e;              /* Expression: portnum
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4_h;              /* Expression: stime
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5_d;              /* Expression: stype
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6_g;              /* Expression: btype
                                        * Referenced by: '<S49>/alpha_VSP2'
                                        */
  real_T omega_VSP1_P1_g;              /* Expression: width
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2_k;              /* Expression: dtype
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3_f;              /* Expression: portnum
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4_l;              /* Expression: stime
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5_n;              /* Expression: stype
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6_f;              /* Expression: btype
                                        * Referenced by: '<S49>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1_j;              /* Expression: width
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2_p;              /* Expression: dtype
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3_p;              /* Expression: portnum
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4_h;              /* Expression: stime
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5_k;              /* Expression: stype
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6_i;              /* Expression: btype
                                        * Referenced by: '<S49>/omega_VSP2'
                                        */
  real_T alpha_VSP1_P1_k;              /* Expression: width
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2_n;              /* Expression: dtype
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3_e;              /* Expression: portnum
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4_b;              /* Expression: stime
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5_g;              /* Expression: stype
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6_n;              /* Expression: btype
                                        * Referenced by: '<S49>/alpha_VSP1'
                                        */
  real_T u_BT_P1_a;                    /* Expression: width
                                        * Referenced by: '<S49>/u_BT'
                                        */
  real_T u_BT_P2_j;                    /* Expression: dtype
                                        * Referenced by: '<S49>/u_BT'
                                        */
  real_T u_BT_P3_n;                    /* Expression: portnum
                                        * Referenced by: '<S49>/u_BT'
                                        */
  real_T u_BT_P4_k;                    /* Expression: stime
                                        * Referenced by: '<S49>/u_BT'
                                        */
  real_T u_BT_P5_d;                    /* Expression: stype
                                        * Referenced by: '<S49>/u_BT'
                                        */
  real_T u_BT_P6_a;                    /* Expression: btype
                                        * Referenced by: '<S49>/u_BT'
                                        */
  real_T u_VSP1_P1_k;                  /* Expression: width
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  real_T u_VSP1_P2_d;                  /* Expression: dtype
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  real_T u_VSP1_P3_n;                  /* Expression: portnum
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  real_T u_VSP1_P4_l;                  /* Expression: stime
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  real_T u_VSP1_P5_g;                  /* Expression: stype
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  real_T u_VSP1_P6_m;                  /* Expression: btype
                                        * Referenced by: '<S49>/u_VSP1'
                                        */
  real_T u_VSP2_P1_g;                  /* Expression: width
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  real_T u_VSP2_P2_c;                  /* Expression: dtype
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  real_T u_VSP2_P3_d;                  /* Expression: portnum
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  real_T u_VSP2_P4_g;                  /* Expression: stime
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  real_T u_VSP2_P5_o;                  /* Expression: stype
                                        * Referenced by: '<S49>/u_VSP2'
                                        */
  real_T u_VSP2_P6_f;                  /* Expression: btype
                                        * Referenced by: '<S49>/u_VSP2'
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
  real_T Memory3_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory3'
                                        */
  real_T Memory1_X0_f[3];              /* Expression: [0 0 0]
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
  real_T eta_d_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/eta_d'
                                        */
  real_T eta_d_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/eta_d'
                                        */
  real_T eta_d_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/eta_d'
                                        */
  real_T eta_d_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/eta_d'
                                        */
  real_T eta_d_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/eta_d'
                                        */
  real_T eta_d_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/eta_d'
                                        */
  real_T eta_0_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/eta_0'
                                        */
  real_T eta_0_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/eta_0'
                                        */
  real_T eta_0_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/eta_0'
                                        */
  real_T eta_0_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/eta_0'
                                        */
  real_T eta_0_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/eta_0'
                                        */
  real_T eta_0_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/eta_0'
                                        */
  real_T bias_1_P1;                    /* Expression: width
                                        * Referenced by: '<S34>/bias_1'
                                        */
  real_T bias_1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S34>/bias_1'
                                        */
  real_T bias_1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S34>/bias_1'
                                        */
  real_T bias_1_P4;                    /* Expression: stime
                                        * Referenced by: '<S34>/bias_1'
                                        */
  real_T bias_1_P5;                    /* Expression: stype
                                        * Referenced by: '<S34>/bias_1'
                                        */
  real_T bias_1_P6;                    /* Expression: btype
                                        * Referenced by: '<S34>/bias_1'
                                        */
  real_T bias_2_P1;                    /* Expression: width
                                        * Referenced by: '<S34>/bias_2'
                                        */
  real_T bias_2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S34>/bias_2'
                                        */
  real_T bias_2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S34>/bias_2'
                                        */
  real_T bias_2_P4;                    /* Expression: stime
                                        * Referenced by: '<S34>/bias_2'
                                        */
  real_T bias_2_P5;                    /* Expression: stype
                                        * Referenced by: '<S34>/bias_2'
                                        */
  real_T bias_2_P6;                    /* Expression: btype
                                        * Referenced by: '<S34>/bias_2'
                                        */
  real_T bias_3_P1;                    /* Expression: width
                                        * Referenced by: '<S34>/bias_3'
                                        */
  real_T bias_3_P2;                    /* Expression: dtype
                                        * Referenced by: '<S34>/bias_3'
                                        */
  real_T bias_3_P3;                    /* Expression: portnum
                                        * Referenced by: '<S34>/bias_3'
                                        */
  real_T bias_3_P4;                    /* Expression: stime
                                        * Referenced by: '<S34>/bias_3'
                                        */
  real_T bias_3_P5;                    /* Expression: stype
                                        * Referenced by: '<S34>/bias_3'
                                        */
  real_T bias_3_P6;                    /* Expression: btype
                                        * Referenced by: '<S34>/bias_3'
                                        */
  real_T x_bar_P1;                     /* Expression: width
                                        * Referenced by: '<S35>/x_bar'
                                        */
  real_T x_bar_P2;                     /* Expression: dtype
                                        * Referenced by: '<S35>/x_bar'
                                        */
  real_T x_bar_P3;                     /* Expression: portnum
                                        * Referenced by: '<S35>/x_bar'
                                        */
  real_T x_bar_P4;                     /* Expression: stime
                                        * Referenced by: '<S35>/x_bar'
                                        */
  real_T x_bar_P5;                     /* Expression: stype
                                        * Referenced by: '<S35>/x_bar'
                                        */
  real_T x_bar_P6;                     /* Expression: btype
                                        * Referenced by: '<S35>/x_bar'
                                        */
  real_T y_bar_P1;                     /* Expression: width
                                        * Referenced by: '<S35>/y_bar'
                                        */
  real_T y_bar_P2;                     /* Expression: dtype
                                        * Referenced by: '<S35>/y_bar'
                                        */
  real_T y_bar_P3;                     /* Expression: portnum
                                        * Referenced by: '<S35>/y_bar'
                                        */
  real_T y_bar_P4;                     /* Expression: stime
                                        * Referenced by: '<S35>/y_bar'
                                        */
  real_T y_bar_P5;                     /* Expression: stype
                                        * Referenced by: '<S35>/y_bar'
                                        */
  real_T y_bar_P6;                     /* Expression: btype
                                        * Referenced by: '<S35>/y_bar'
                                        */
  real_T psi_bar_P1;                   /* Expression: width
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  real_T psi_bar_P2;                   /* Expression: dtype
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  real_T psi_bar_P3;                   /* Expression: portnum
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  real_T psi_bar_P4;                   /* Expression: stime
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  real_T psi_bar_P5;                   /* Expression: stype
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  real_T psi_bar_P6;                   /* Expression: btype
                                        * Referenced by: '<S35>/psi_bar'
                                        */
  real_T psi_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  real_T psi_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  real_T psi_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  real_T psi_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  real_T psi_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  real_T psi_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S36>/psi_hat'
                                        */
  real_T x_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S36>/x_hat'
                                        */
  real_T x_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S36>/x_hat'
                                        */
  real_T x_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S36>/x_hat'
                                        */
  real_T x_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S36>/x_hat'
                                        */
  real_T x_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S36>/x_hat'
                                        */
  real_T x_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S36>/x_hat'
                                        */
  real_T y_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S36>/y_hat'
                                        */
  real_T y_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S36>/y_hat'
                                        */
  real_T y_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S36>/y_hat'
                                        */
  real_T y_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S36>/y_hat'
                                        */
  real_T y_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S36>/y_hat'
                                        */
  real_T y_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S36>/y_hat'
                                        */
  real_T r_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T r_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T r_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T r_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T r_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T r_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T u_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T u_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T u_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T u_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T u_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T u_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T v_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T v_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T v_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T v_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T v_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T v_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T L12_P1;                       /* Expression: width
                                        * Referenced by: '<S30>/L12'
                                        */
  real_T L12_P2;                       /* Expression: dtype
                                        * Referenced by: '<S30>/L12'
                                        */
  real_T L12_P3;                       /* Expression: portnum
                                        * Referenced by: '<S30>/L12'
                                        */
  real_T L12_P4;                       /* Expression: stime
                                        * Referenced by: '<S30>/L12'
                                        */
  real_T L12_P5;                       /* Expression: stype
                                        * Referenced by: '<S30>/L12'
                                        */
  real_T L12_P6;                       /* Expression: btype
                                        * Referenced by: '<S30>/L12'
                                        */
  real_T L11_P1;                       /* Expression: width
                                        * Referenced by: '<S30>/L11'
                                        */
  real_T L11_P2;                       /* Expression: dtype
                                        * Referenced by: '<S30>/L11'
                                        */
  real_T L11_P3;                       /* Expression: portnum
                                        * Referenced by: '<S30>/L11'
                                        */
  real_T L11_P4;                       /* Expression: stime
                                        * Referenced by: '<S30>/L11'
                                        */
  real_T L11_P5;                       /* Expression: stype
                                        * Referenced by: '<S30>/L11'
                                        */
  real_T L11_P6;                       /* Expression: btype
                                        * Referenced by: '<S30>/L11'
                                        */
  real_T L13_P1;                       /* Expression: width
                                        * Referenced by: '<S30>/L13'
                                        */
  real_T L13_P2;                       /* Expression: dtype
                                        * Referenced by: '<S30>/L13'
                                        */
  real_T L13_P3;                       /* Expression: portnum
                                        * Referenced by: '<S30>/L13'
                                        */
  real_T L13_P4;                       /* Expression: stime
                                        * Referenced by: '<S30>/L13'
                                        */
  real_T L13_P5;                       /* Expression: stype
                                        * Referenced by: '<S30>/L13'
                                        */
  real_T L13_P6;                       /* Expression: btype
                                        * Referenced by: '<S30>/L13'
                                        */
  real_T L21_P1;                       /* Expression: width
                                        * Referenced by: '<S31>/L21'
                                        */
  real_T L21_P2;                       /* Expression: dtype
                                        * Referenced by: '<S31>/L21'
                                        */
  real_T L21_P3;                       /* Expression: portnum
                                        * Referenced by: '<S31>/L21'
                                        */
  real_T L21_P4;                       /* Expression: stime
                                        * Referenced by: '<S31>/L21'
                                        */
  real_T L21_P5;                       /* Expression: stype
                                        * Referenced by: '<S31>/L21'
                                        */
  real_T L21_P6;                       /* Expression: btype
                                        * Referenced by: '<S31>/L21'
                                        */
  real_T L22_P1;                       /* Expression: width
                                        * Referenced by: '<S31>/L22'
                                        */
  real_T L22_P2;                       /* Expression: dtype
                                        * Referenced by: '<S31>/L22'
                                        */
  real_T L22_P3;                       /* Expression: portnum
                                        * Referenced by: '<S31>/L22'
                                        */
  real_T L22_P4;                       /* Expression: stime
                                        * Referenced by: '<S31>/L22'
                                        */
  real_T L22_P5;                       /* Expression: stype
                                        * Referenced by: '<S31>/L22'
                                        */
  real_T L22_P6;                       /* Expression: btype
                                        * Referenced by: '<S31>/L22'
                                        */
  real_T L23_P1;                       /* Expression: width
                                        * Referenced by: '<S31>/L23'
                                        */
  real_T L23_P2;                       /* Expression: dtype
                                        * Referenced by: '<S31>/L23'
                                        */
  real_T L23_P3;                       /* Expression: portnum
                                        * Referenced by: '<S31>/L23'
                                        */
  real_T L23_P4;                       /* Expression: stime
                                        * Referenced by: '<S31>/L23'
                                        */
  real_T L23_P5;                       /* Expression: stype
                                        * Referenced by: '<S31>/L23'
                                        */
  real_T L23_P6;                       /* Expression: btype
                                        * Referenced by: '<S31>/L23'
                                        */
  real_T L31_P1;                       /* Expression: width
                                        * Referenced by: '<S32>/L31'
                                        */
  real_T L31_P2;                       /* Expression: dtype
                                        * Referenced by: '<S32>/L31'
                                        */
  real_T L31_P3;                       /* Expression: portnum
                                        * Referenced by: '<S32>/L31'
                                        */
  real_T L31_P4;                       /* Expression: stime
                                        * Referenced by: '<S32>/L31'
                                        */
  real_T L31_P5;                       /* Expression: stype
                                        * Referenced by: '<S32>/L31'
                                        */
  real_T L31_P6;                       /* Expression: btype
                                        * Referenced by: '<S32>/L31'
                                        */
  real_T L32_P1;                       /* Expression: width
                                        * Referenced by: '<S32>/L32'
                                        */
  real_T L32_P2;                       /* Expression: dtype
                                        * Referenced by: '<S32>/L32'
                                        */
  real_T L32_P3;                       /* Expression: portnum
                                        * Referenced by: '<S32>/L32'
                                        */
  real_T L32_P4;                       /* Expression: stime
                                        * Referenced by: '<S32>/L32'
                                        */
  real_T L32_P5;                       /* Expression: stype
                                        * Referenced by: '<S32>/L32'
                                        */
  real_T L32_P6;                       /* Expression: btype
                                        * Referenced by: '<S32>/L32'
                                        */
  real_T L33_P1;                       /* Expression: width
                                        * Referenced by: '<S32>/L33'
                                        */
  real_T L33_P2;                       /* Expression: dtype
                                        * Referenced by: '<S32>/L33'
                                        */
  real_T L33_P3;                       /* Expression: portnum
                                        * Referenced by: '<S32>/L33'
                                        */
  real_T L33_P4;                       /* Expression: stime
                                        * Referenced by: '<S32>/L33'
                                        */
  real_T L33_P5;                       /* Expression: stype
                                        * Referenced by: '<S32>/L33'
                                        */
  real_T L33_P6;                       /* Expression: btype
                                        * Referenced by: '<S32>/L33'
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
  real_T s1_P1;                        /* Expression: width
                                        * Referenced by: '<S8>/s1'
                                        */
  real_T s1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S8>/s1'
                                        */
  real_T s1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S8>/s1'
                                        */
  real_T s1_P4;                        /* Expression: stime
                                        * Referenced by: '<S8>/s1'
                                        */
  real_T s1_P5;                        /* Expression: stype
                                        * Referenced by: '<S8>/s1'
                                        */
  real_T s1_P6;                        /* Expression: btype
                                        * Referenced by: '<S8>/s1'
                                        */
  real_T s2_P1;                        /* Expression: width
                                        * Referenced by: '<S8>/s2'
                                        */
  real_T s2_P2;                        /* Expression: dtype
                                        * Referenced by: '<S8>/s2'
                                        */
  real_T s2_P3;                        /* Expression: portnum
                                        * Referenced by: '<S8>/s2'
                                        */
  real_T s2_P4;                        /* Expression: stime
                                        * Referenced by: '<S8>/s2'
                                        */
  real_T s2_P5;                        /* Expression: stype
                                        * Referenced by: '<S8>/s2'
                                        */
  real_T s2_P6;                        /* Expression: btype
                                        * Referenced by: '<S8>/s2'
                                        */
  real_T NIVeriStandSignalProbe_P1;    /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_student_HIL_T {
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
    real_T odeY[10];
    real_T odeF[4][10];
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
extern P_ctrl_student_HIL_T ctrl_student_HIL_P;

/* Block signals (auto storage) */
extern B_ctrl_student_HIL_T ctrl_student_HIL_B;

/* Continuous states (auto storage) */
extern X_ctrl_student_HIL_T ctrl_student_HIL_X;

/* Block states (auto storage) */
extern DW_ctrl_student_HIL_T ctrl_student_HIL_DW;

/* Model entry point functions */
extern void ctrl_student_HIL_initialize(void);
extern void ctrl_student_HIL_output(void);
extern void ctrl_student_HIL_update(void);
extern void ctrl_student_HIL_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_student_HIL_rtModel *ctrl_student_HIL(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_student_HIL_T *const ctrl_student_HIL_M;

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
 * '<Root>' : 'ctrl_student_HIL'
 * '<S1>'   : 'ctrl_student_HIL/DP-system'
 * '<S2>'   : 'ctrl_student_HIL/Noise generator1'
 * '<S3>'   : 'ctrl_student_HIL/Observer'
 * '<S4>'   : 'ctrl_student_HIL/Switch joystick  and DP-system'
 * '<S5>'   : 'ctrl_student_HIL/dead rec  switch'
 * '<S6>'   : 'ctrl_student_HIL/eta_noise_ut'
 * '<S7>'   : 'ctrl_student_HIL/joystick1'
 * '<S8>'   : 'ctrl_student_HIL/signal dropout check '
 * '<S9>'   : 'ctrl_student_HIL/switch'
 * '<S10>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)'
 * '<S11>'  : 'ctrl_student_HIL/DP-system/Ellipsoidal path'
 * '<S12>'  : 'ctrl_student_HIL/DP-system/Kd'
 * '<S13>'  : 'ctrl_student_HIL/DP-system/MATLAB Function'
 * '<S14>'  : 'ctrl_student_HIL/DP-system/Straight -line '
 * '<S15>'  : 'ctrl_student_HIL/DP-system/controller'
 * '<S16>'  : 'ctrl_student_HIL/DP-system/inputs'
 * '<S17>'  : 'ctrl_student_HIL/DP-system/signal switch '
 * '<S18>'  : 'ctrl_student_HIL/DP-system/update law'
 * '<S19>'  : 'ctrl_student_HIL/DP-system/z1-jjz2'
 * '<S20>'  : 'ctrl_student_HIL/DP-system/Kd/MATLAB Function'
 * '<S21>'  : 'ctrl_student_HIL/Noise generator1/Downsample	signal'
 * '<S22>'  : 'ctrl_student_HIL/Noise generator1/Sample & hold'
 * '<S23>'  : 'ctrl_student_HIL/Noise generator1/noise generator'
 * '<S24>'  : 'ctrl_student_HIL/Noise generator1/Downsample	signal/MATLAB Function'
 * '<S25>'  : 'ctrl_student_HIL/Noise generator1/Sample & hold/MATLAB Function1'
 * '<S26>'  : 'ctrl_student_HIL/Noise generator1/noise generator/Band-limited white noise psi'
 * '<S27>'  : 'ctrl_student_HIL/Noise generator1/noise generator/Band-limited white noise x'
 * '<S28>'  : 'ctrl_student_HIL/Noise generator1/noise generator/Band-limited white noise y'
 * '<S29>'  : 'ctrl_student_HIL/Observer/D'
 * '<S30>'  : 'ctrl_student_HIL/Observer/L1'
 * '<S31>'  : 'ctrl_student_HIL/Observer/L2'
 * '<S32>'  : 'ctrl_student_HIL/Observer/L3'
 * '<S33>'  : 'ctrl_student_HIL/Observer/Rotation matrix'
 * '<S34>'  : 'ctrl_student_HIL/Observer/bias_bar'
 * '<S35>'  : 'ctrl_student_HIL/Observer/eta_bar_ut'
 * '<S36>'  : 'ctrl_student_HIL/Observer/eta_hat_ut'
 * '<S37>'  : 'ctrl_student_HIL/Observer/nu_hat_ut'
 * '<S38>'  : 'ctrl_student_HIL/Observer/L1/MATLAB Function'
 * '<S39>'  : 'ctrl_student_HIL/Observer/L2/MATLAB Function'
 * '<S40>'  : 'ctrl_student_HIL/Observer/L3/MATLAB Function'
 * '<S41>'  : 'ctrl_student_HIL/joystick1/MATLAB Function'
 * '<S42>'  : 'ctrl_student_HIL/joystick1/Thrust allocation'
 * '<S43>'  : 'ctrl_student_HIL/signal dropout check /MATLAB Function'
 * '<S44>'  : 'ctrl_student_HIL/switch/Switch_function'
 * '<S45>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Full thrust allocation'
 * '<S46>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/Limited allocation: VSP only  in surge and BT only in yaw'
 * '<S47>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship'
 * '<S48>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking'
 * '<S49>'  : 'ctrl_student_HIL/tau to real ship (only use in MCLab)/To thruster of real ship/u'
 */
#endif                                 /* RTW_HEADER_ctrl_student_HIL_h_ */

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#define NI_SIT_PARAMS
#ifdef NI_ROOTMODEL_ctrl_student_HIL
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

P_ctrl_student_HIL_T rtParameter[NUMST+!TID01EQ];
P_ctrl_student_HIL_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

P_ctrl_student_HIL_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

extern int tid;
extern P_ctrl_student_HIL_T* param_lookup[NUMST][2];

#else

extern P_ctrl_student_HIL_T rtParameter[];

#endif
#endif

#ifdef MULTITASKING
#define ctrl_student_HIL_P             (*param_lookup[tid][READSIDE])
#else
#define ctrl_student_HIL_P             rtParameter[READSIDE]
#endif
#endif
#endif

/* file: init_parameter.cpp */
/*******************************************************************************
* Copyright 2014-2018 Intel Corporation.
*
* This software and the related documents are Intel copyrighted  materials,  and
* your use of  them is  governed by the  express license  under which  they were
* provided to you (License).  Unless the License provides otherwise, you may not
* use, modify, copy, publish, distribute,  disclose or transmit this software or
* the related documents without Intel's prior written permission.
*
* This software and the related documents  are provided as  is,  with no express
* or implied  warranties,  other  than those  that are  expressly stated  in the
* License.
*******************************************************************************/

#include <jni.h>

#include "daal.h"
#include "em_gmm/init/JInitParameter.h"
#include "em_gmm/init/JInitMethod.h"

#include "common_helpers.h"

USING_COMMON_NAMESPACES();
using namespace daal::algorithms::em_gmm::init;

#define DefaultDense    com_intel_daal_algorithms_em_gmm_init_InitMethod_DefaultDenseValue

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cInit
 * Signature: (JIIIJJJD)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cInit
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method, jint cmode, jlong nComponents, jlong nTrials, jlong nDepthIter, jdouble accThr)
{
    em_gmm::init::Parameter *parameterAddr =
        (em_gmm::init::Parameter *)jniBatch<em_gmm::init::Method, Batch, defaultDense>::getParameter(prec, method, algAddr);

    if(parameterAddr)
    {
        parameterAddr->nComponents = nComponents;
        parameterAddr->nIterations = nDepthIter;
        parameterAddr->nTrials = nTrials;
        parameterAddr->accuracyThreshold = accThr;
    }

    return (jlong)parameterAddr;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cGetNComponents
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cGetNComponents
(JNIEnv *env, jobject thisObj, jlong parameterAddress)
{
    return((em_gmm::init::Parameter *)parameterAddress)->nComponents;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cGetDepthIterations
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cGetDepthIterations
(JNIEnv *env, jobject thisObj, jlong parameterAddress)
{
    return((em_gmm::init::Parameter *)parameterAddress)->nIterations;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cGetNTrials
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cGetNTrials
(JNIEnv *env, jobject thisObj, jlong parameterAddress)
{
    return((em_gmm::init::Parameter *)parameterAddress)->nTrials;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cGetStartSeed
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cGetStartSeed
(JNIEnv *, jobject, jlong parameterAddress)
{
    return((em_gmm::init::Parameter *)parameterAddress)->seed;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cGetAccuracyThreshold
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cGetAccuracyThreshold
(JNIEnv *env, jobject thisObj, jlong parameterAddress)
{
    return((em_gmm::init::Parameter *)parameterAddress)->accuracyThreshold;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cSetNComponents
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cSetNComponents
(JNIEnv *env, jobject thisObj, jlong parameterAddress, jlong nComponents)
{
    ((em_gmm::init::Parameter *)parameterAddress)->nComponents = nComponents;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cSetNDepthIterations
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cSetNDepthIterations
(JNIEnv *env, jobject thisObj, jlong parameterAddress, jlong nIterations)
{
    ((em_gmm::init::Parameter *)parameterAddress)->nIterations = nIterations;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cSetNTrials
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cSetNTrials
(JNIEnv *env, jobject thisObj, jlong parameterAddress, jlong nTrials)
{
    ((em_gmm::init::Parameter *)parameterAddress)->nTrials = nTrials;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cSetStartSeed
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cSetStartSeed
(JNIEnv *, jobject, jlong parameterAddress, jlong seed)
{
    ((em_gmm::init::Parameter *)parameterAddress)->seed = seed;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cSetAccuracyThreshold
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cSetAccuracyThreshold
(JNIEnv *env, jobject thisObj, jlong parameterAddress, jdouble accuracyThreshold)
{
    ((em_gmm::init::Parameter *)parameterAddress)->accuracyThreshold = accuracyThreshold;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cSetCovarianceStorage
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cSetCovarianceStorage
(JNIEnv *, jobject, jlong parameterAddress, jint covarianceStorage)
{
    ((em_gmm::init::Parameter *)parameterAddress)->covarianceStorage = (em_gmm::CovarianceStorageId)covarianceStorage;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cGetCovarianceStorage
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cGetCovarianceStorage
(JNIEnv *, jobject, jlong parameterAddress)
{
    return (jint)((em_gmm::init::Parameter *)parameterAddress)->covarianceStorage;
}

/*
 * Class:     com_intel_daal_algorithms_em_gmm_init_InitParameter
 * Method:    cSetEngine
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_em_1gmm_init_InitParameter_cSetEngine
(JNIEnv *env, jobject thisObj, jlong cParameter, jlong engineAddr)
{
    (((em_gmm::init::Parameter *)cParameter))->engine = staticPointerCast<engines::BatchBase, AlgorithmIface> (*(SharedPtr<AlgorithmIface> *)engineAddr);
}

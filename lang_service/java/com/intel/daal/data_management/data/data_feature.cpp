/* file: data_feature.cpp */
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
#include <string>

#include "JDataFeature.h"
#include "JDataFeatureUtils.h"
#include "data_dictionary.h"

using namespace daal::data_management;
using namespace daal::services;

inline static jlong getDataFeatureObject(JNIEnv *env, jobject thisObj)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    jclass cls = env->FindClass("com/intel/daal/data_management/data/DataFeature");
    jfieldID objFieldID = env->GetFieldID(cls, "cObject", "J");
    return env->GetLongField(thisObj, objFieldID);
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    init
 * Signature:()J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_data_1management_data_DataFeature_init
(JNIEnv *env, jobject thisObj)
{
    using namespace daal;

    // Create C++ object of the class NumericTableFeature
    NumericTableFeaturePtr *df = new SharedPtr<NumericTableFeature>(new NumericTableFeature());
    return(jlong)df;
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cDispose
 * Signature:(J)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cDispose
(JNIEnv *env, jobject thisObj, jlong dataFeatureAddr)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    if(dataFeatureAddr) delete (NumericTableFeaturePtr *)dataFeatureAddr;
}


/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cSerializeCObject
 * Signature:(J)Ljava/nio/ByteBuffer;
 */
JNIEXPORT jobject JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cSerializeCObject
(JNIEnv *env, jobject thisObj, jlong dataFeatureAddr)
{
    using namespace daal;
    using namespace daal::services;
    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)dataFeatureAddr)->get();

    InputDataArchive dataArch;
    df->serialize(dataArch);

    size_t length = dataArch.getSizeOfArchive();

    byte *buffer = (byte *)daal_malloc(length);
    dataArch.copyArchiveToArray(buffer, length);

    return env->NewDirectByteBuffer(buffer, length);
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cDeserializeCObject
 * Signature:(Ljava/nio/ByteBuffer;J)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cDeserializeCObject
(JNIEnv *env, jobject thisObj, jobject byteBuffer, jlong size)
{
    using namespace daal;
    byte *buffer = (byte *)(env->GetDirectBufferAddress(byteBuffer));
    OutputDataArchive dataArch(buffer, (size_t)size);
    NumericTableFeature *df = new NumericTableFeature();
    df->deserialize(dataArch);
    return(jlong)df;
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cSetInternalNumType
 * Signature:(JI)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cSetInternalNumType
(JNIEnv *env, jobject thisObj, jlong dataFeatureAddr, jint newIntType)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)dataFeatureAddr)->get();
    //df->int_type =(DataFeatureUtils::InternalNumType)((int)newIntType);
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cSetPMMLNumType
 * Signature:(JI)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cSetPMMLNumType
(JNIEnv *env, jobject thisObj, jlong dataFeatureAddr, jint newPMMLType)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)dataFeatureAddr)->get();
    df->pmmlType = (data_feature_utils::PMMLNumType)((int)newPMMLType);
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cSetFeatureType
 * Signature:(JI)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cSetFeatureType
(JNIEnv *env, jobject thisObj, jlong dataFeatureAddr, jint newFeatureType)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)dataFeatureAddr)->get();
    df->featureType = (data_feature_utils::FeatureType)((int)newFeatureType);
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cSetCategoryNumber
 * Signature:(JI)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cSetCategoryNumber
(JNIEnv *env, jobject thisObj, jlong dataFeatureAddr, jint categoryNumber)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)dataFeatureAddr)->get();
    df->categoryNumber = (int)categoryNumber;
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    getPMMLNumType
 * Signature:()Lcom/intel/daal/data_management/data/DataFeatureUtils/PMMLNumType;
 */
JNIEXPORT jobject JNICALL Java_com_intel_daal_data_1management_data_DataFeature_getPMMLNumType
(JNIEnv *env, jobject thisObj)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)getDataFeatureObject(env, thisObj))->get();

    // Wrap resulting C++ table with Java object
    jclass resultClass = env->FindClass("com/intel/daal/data_management/data/DataFeatureUtils$PMMLNumType");
    if(resultClass == 0)
    {
        /* printf("Couldn't find class DataFeatureUtils$InternalNumType\n"); fflush(0); */
        return NULL;
    }

    switch((long long)(df->pmmlType))
    {
    case com_intel_daal_data_management_data_DataFeatureUtils_cDaalGenFloat:
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_GEN_FLOAT",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$PMMLNumType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    case com_intel_daal_data_management_data_DataFeatureUtils_cDaalGenDouble:
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_GEN_DOUBLE",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$PMMLNumType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    case com_intel_daal_data_management_data_DataFeatureUtils_cDaalGenInteger:
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_GEN_INTEGER",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$PMMLNumType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    case com_intel_daal_data_management_data_DataFeatureUtils_cDaalGenBoolean:
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_GEN_BOOLEAN",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$PMMLNumType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    case com_intel_daal_data_management_data_DataFeatureUtils_cDaalGenString:
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_GEN_STRING",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$PMMLNumType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    case com_intel_daal_data_management_data_DataFeatureUtils_cDaalGenUnknown:
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_GEN_UNKNOWN",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$PMMLNumType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    default: /* DAAL_GEN_UNKNOWN */
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_GEN_UNKNOWN",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$PMMLNumType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    }

    return NULL;
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    getFeatureType
 * Signature:()Lcom/intel/daal/data_management/data/DataFeatureUtils/FeatureType;
 */
JNIEXPORT jobject JNICALL Java_com_intel_daal_data_1management_data_DataFeature_getFeatureType
(JNIEnv *env, jobject thisObj)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)getDataFeatureObject(env, thisObj))->get();

    // Wrap resulting C++ table with Java object
    jclass resultClass = env->FindClass("com/intel/daal/data_management/data/DataFeatureUtils$FeatureType");
    if(resultClass == 0)
    {
        /* printf("Couldn't find class DataFeatureUtils$InternalNumType\n"); fflush(0); */
        return NULL;
    }
    switch((long long)(df->featureType))
    {
    case com_intel_daal_data_management_data_DataFeatureUtils_cDaalCategorical:
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_CATEGORICAL",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$FeatureType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    case com_intel_daal_data_management_data_DataFeatureUtils_cDaalOrdinal:
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_ORDINAL",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$FeatureType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    case com_intel_daal_data_management_data_DataFeatureUtils_cDaalContinuous:
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_CONTINUOUS",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$FeatureType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    default: /* DAAL_CONTINUOUS */
    {
        jfieldID staticFieldID = env->GetStaticFieldID(resultClass , "DAAL_CONTINUOUS",
                                                       "Lcom/intel/daal/data_management/data/DataFeatureUtils$FeatureType;");
        return env->GetStaticObjectField(resultClass, staticFieldID);
    }
    }

    return NULL;
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    getCategoryNumber
 * Signature:()I
 */
JNIEXPORT jint JNICALL Java_com_intel_daal_data_1management_data_DataFeature_getCategoryNumber
(JNIEnv *env, jobject thisObj)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)getDataFeatureObject(env, thisObj))->get();
    return(jint)(df->categoryNumber);
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    getName
 * Signature:()Ljava/lang/String;
 */
/*
JNIEXPORT jstring JNICALL Java_com_intel_daal_data_1management_data_DataFeature_getName
 (JNIEnv *env, jobject thisObj)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((services::SharedPtr<NumericTableFeature> *)getDataFeatureObject(env, thisObj))->get();
    return env->NewStringUTF(df->name);
}
*/

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cSetDoubleType
 * Signature:(J)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cSetDoubleType
(JNIEnv *env, jobject thisObj, jlong dataFeatureAddr)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)dataFeatureAddr)->get();
    df->setType<double>();
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cSetFloatType
 * Signature:()V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cSetFloatType
(JNIEnv *env, jobject thisObj, jlong dataFeatureAddr)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)dataFeatureAddr)->get();
    df->setType<float>();
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cSetLongType
 * Signature:()V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cSetLongType
(JNIEnv *env, jobject thisObj, jlong dataFeatureAddr)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)dataFeatureAddr)->get();
    df->setType<long>();
}

/*
 * Class:     com_intel_daal_data_1management_data_DataFeature
 * Method:    cSetIntType
 * Signature:()V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_data_1management_data_DataFeature_cSetIntType
(JNIEnv *env, jobject thisObj, jlong dataFeatureAddr)
{
    using namespace daal;

    // Get a class reference for Java NumericTableFeature
    NumericTableFeature *df = ((NumericTableFeaturePtr *)dataFeatureAddr)->get();
    df->setType<int>();
}

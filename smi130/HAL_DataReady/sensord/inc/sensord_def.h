/*!
 * @section LICENSE
 *
 * (C) Copyright 2011~2015 Bosch Sensortec GmbH All Rights Reserved
 *
 * (C) Modification Copyright 2018 Robert Bosch Kft  All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Special: Description of the Software:
 *
 * This software module (hereinafter called "Software") and any
 * information on application-sheets (hereinafter called "Information") is
 * provided free of charge for the sole purpose to support your application
 * work. 
 *
 * As such, the Software is merely an experimental software, not tested for
 * safety in the field and only intended for inspiration for further development 
 * and testing. Any usage in a safety-relevant field of use (like automotive,
 * seafaring, spacefaring, industrial plants etc.) was not intended, so there are
 * no precautions for such usage incorporated in the Software.
 * 
 * The Software is specifically designed for the exclusive use for Bosch
 * Sensortec products by personnel who have special experience and training. Do
 * not use this Software if you do not have the proper experience or training.
 * 
 * This Software package is provided as is and without any expressed or
 * implied warranties, including without limitation, the implied warranties of
 * merchantability and fitness for a particular purpose.
 * 
 * Bosch Sensortec and their representatives and agents deny any liability for
 * the functional impairment of this Software in terms of fitness, performance
 * and safety. Bosch Sensortec and their representatives and agents shall not be
 * liable for any direct or indirect damages or injury, except as otherwise
 * stipulated in mandatory applicable law.
 * The Information provided is believed to be accurate and reliable. Bosch
 * Sensortec assumes no responsibility for the consequences of use of such
 * Information nor for any infringement of patents or other rights of third
 * parties which may result from its use.
 * 
 *------------------------------------------------------------------------------
 * The following Product Disclaimer does not apply to the BSX4-HAL-4.1NoFusion Software 
 * which is licensed under the Apache License, Version 2.0 as stated above.  
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Product Disclaimer
 *
 * Common:
 *
 * Assessment of Products Returned from Field
 *
 * Returned products are considered good if they fulfill the specifications / 
 * test data for 0-mileage and field listed in this document.
 *
 * Engineering Samples
 * 
 * Engineering samples are marked with (e) or (E). Samples may vary from the
 * valid technical specifications of the series product contained in this
 * data sheet. Therefore, they are not intended or fit for resale to
 * third parties or for use in end products. Their sole purpose is internal
 * client testing. The testing of an engineering sample may in no way replace
 * the testing of a series product. Bosch assumes no liability for the use
 * of engineering samples. The purchaser shall indemnify Bosch from all claims
 * arising from the use of engineering samples.
 *
 * Intended use
 *
 * Provided that SMI130 is used within the conditions (environment, application,
 * installation, loads) as described in this TCD and the corresponding
 * agreed upon documents, Bosch ensures that the product complies with
 * the agreed properties. Agreements beyond this require
 * the written approval by Bosch. The product is considered fit for the intended
 * use when the product successfully has passed the tests
 * in accordance with the TCD and agreed upon documents.
 *
 * It is the responsibility of the customer to ensure the proper application
 * of the product in the overall system/vehicle.
 *
 * Bosch does not assume any responsibility for changes to the environment
 * of the product that deviate from the TCD and the agreed upon documents 
 * as well as all applications not released by Bosch
  *
 * The resale and/or use of products are at the purchaser’s own risk and 
 * responsibility. The examination and testing of the SMI130 
 * is the sole responsibility of the purchaser.
 *
 * The purchaser shall indemnify Bosch from all third party claims 
 * arising from any product use not covered by the parameters of 
 * this product data sheet or not approved by Bosch and reimburse Bosch 
 * for all costs and damages in connection with such claims.
 *
 * The purchaser must monitor the market for the purchased products,
 * particularly with regard to product safety, and inform Bosch without delay
 * of all security relevant incidents.
 *
 * Application Examples and Hints
 *
 * With respect to any application examples, advice, normal values
 * and/or any information regarding the application of the device,
 * Bosch hereby disclaims any and all warranties and liabilities of any kind,
 * including without limitation warranties of
 * non-infringement of intellectual property rights or copyrights
 * of any third party.
 * The information given in this document shall in no event be regarded 
 * as a guarantee of conditions or characteristics. They are provided
 * for illustrative purposes only and no evaluation regarding infringement
 * of intellectual property rights or copyrights or regarding functionality,
 * performance or error has been made.
 *
 * @file         sensord_def.h
 * @date         "Thu Aug 27 01:58:58 2015 -0400"
 * @commit       "7184568"
 *
 * @modification date         "Thu May 3 12:23:56 2018 +0100"
 *
 * @brief
 *
 * @detail
 *
 */

#ifndef __SENSORD_DEF_H
#define __SENSORD_DEF_H

#if defined(__FASTEST_MODE_100HZ__)
#define BST_SENSOR_MINDELAY_uS 10000
#else
#define BST_SENSOR_MINDELAY_uS 5000
#endif

/* this value depends on the reporting mode:
 *
 *   continuous: minimum sample period allowed in microseconds
 *   on-change : 0
 *   one-shot  :-1
 *   special   : 0, unless otherwise noted
 */
#define SENSOR_MINDELAY_ONCHANGE 200000 //BSX4 library can only support minimum 200ms(200000us) delay
#define SENSOR_MINDELAY_ONESHOT (-1)
#define SENSOR_MINDELAY_SPECIAL 0

/* This value is defined only for continuous mode and on-change sensors. It is the delay between
 * two sensor events corresponding to the lowest frequency that this sensor supports. When lower
 * frequencies are requested through batch()/setDelay() the events will be generated at this
 * frequency instead. It can be used by the framework or applications to estimate when the batch
 * FIFO may be full.
 *
 * NOTE: 1) period_ns is in nanoseconds where as maxDelay/minDelay are in microseconds.
 *              continuous, on-change: maximum sampling period allowed in microseconds.
 *              one-shot, special : 0
 *   2) maxDelay should always fit within a 32 bit signed integer. It is declared as 64 bit
 *      on 64 bit architectures only for binary compatibility reasons.
 * Availability: SENSORS_DEVICE_API_VERSION_1_3
 */
#define SENSOR_MAXDELAY_ONESHOT 0
#define SENSOR_MAXDELAY_SPECIAL 0
/*for ON_CHANGE type, sample period is actually a delay period between events reporting
 * so define a default value here
 */
#define SENSOR_MAXDELAY_ONCHANGE 1800000000 //BSX4 library support maximum 1800s(1800000000us) delay

#define BATCH_RSV_FRAME_COUNT 0
#define BATCH_MAX_FRAME_COUNT 2000

typedef struct
{
    uint32_t id;
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        struct
        {
            float azimuth;
            float pitch;
            float roll;
        }; //for ORIENTATION
        float pressure;
        float temperature;
        float data[4]; // for RV, Game RV, ALSH debug raw data
        struct
        {
            float x_uncalib;
            float y_uncalib;
            float z_uncalib;
            float x_bias;
            float y_bias;
            float z_bias;
        }; //for GYROSCOPE/MAGNETIC UNCALIBRATED
        uint64_t step_counter;
        struct
        {
            float heart_rate_bpm;
            int8_t heart_rate_status;
        };
        float relative_humidity;
        float ambient_temperature;
        float light;
        float proximity;

        //ALSH private virtual sensor
        int32_t power_consumption;
        int32_t activity_wakeup;
    };

    int8_t accuracy;
    int64_t timestamp;
} HW_DATA_UNION;

/* this path must exist and user <system> must have permission to write to it */
#if !defined(PLTF_LINUX_ENABLED)
#define PATH_DIR_SENSOR_STORAGE "/data/misc/sensord_stor"
#else
#if defined(SENSORD_STOR)
#define PATH_DIR_SENSOR_STORAGE SENSORD_STOR"/sensord_stor"
#else
#define PATH_DIR_SENSOR_STORAGE "/root/My_C/sensord_stor"
#endif
#endif


#endif

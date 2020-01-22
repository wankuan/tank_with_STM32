/*----------------------------------------------------------------------------
 * Tencent is pleased to support the open source community by making TencentOS
 * available.
 *
 * Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
 * If you have downloaded a copy of the TencentOS binary from Tencent, please
 * note that the TencentOS binary is licensed under the BSD 3-Clause License.
 *
 * If you have downloaded a copy of the TencentOS source code from Tencent,
 * please note that TencentOS source code is licensed under the BSD 3-Clause
 * License, except for the third-party components listed below which are
 * subject to different license terms. Your integration of TencentOS into your
 * own projects may require compliance with the BSD 3-Clause License, as well
 * as the other licenses applicable to the third-party components included
 * within TencentOS.
 *---------------------------------------------------------------------------*/

#ifndef _TOS_EVTDRV_TICK_H_
#define  _TOS_EVTDRV_TICK_H_

#if TOS_CFG_EVENT_DRIVEN_EN > 0u

/**
 * @brief Get the current systick cout.
 *
 * @attention
 *
 * @return  current systick count.
 */
__API__ evtdrv_tick_t tos_evtdrv_systick_get(void);

/**
 * @brief tick interrupt handler.
 *
 * @attention   if you wanna use event-driven timer, you must deal with the tick.
 *
 * @return  None.
 */
__API__ void tos_evtdrv_tick_handler(void);

/**
 * @brief Convert tick count to milli-seconds.
 *
 * @attention
 *
 * @return  the milli-seconds equals to the tick count.
 */
__API__ evtdrv_time_t tos_evtdrv_tick2millisec(evtdrv_tick_t tick);

/**
 * @brief Convert milli-seconds to tick count.
 *
 * @attention
 *
 * @return  the tick count equals to the tick count.
 */
__API__ evtdrv_tick_t tos_evtdrv_millisec2tick(evtdrv_time_t ms);

#endif /* TOS_CFG_EVENT_DRIVEN_EN */

#endif /* _TOS_EVTDRV_TICK_H_ */


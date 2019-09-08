    1 /*
    2  * Copyright (C) 2010 The Paparazzi Team
    3  *
    4  * This file is part of paparazzi.
    5  *
    6  * paparazzi is free software; you can redistribute it and/or modify
    7  * it under the terms of the GNU General Public License as published by
    8  * the Free Software Foundation; either version 2, or (at your option)
    9  * any later version.
   10  *
   11  * paparazzi is distributed in the hope that it will be useful,
   12  * but WITHOUT ANY WARRANTY; without even the implied warranty of
   13  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   14  * GNU General Public License for more details.
   15  *
   16  * You should have received a copy of the GNU General Public License
   17  * along with paparazzi; see the file COPYING.  If not, write to
   18  * the Free Software Foundation, 59 Temple Place - Suite 330,
   19  * Boston, MA 02111-1307, USA.
   20  */
   21 
   22 
   36 #ifndef DC_H
   37 #define DC_H
   38 
   39 #include "float.h"
   40 #include "std.h"
   41 #include "state.h"
   42 #include "generated/airframe.h"
   43 #include "subsystems/gps.h"
   44 
   46 extern uint16_t dc_photo_nr;
   47 
   49 extern uint16_t dc_gps_count;
   50 
   51 
   52 /*
   53  * Variables for PERIODIC mode.
   54  */
   56 extern float dc_autoshoot_period;
   57 
   58 
   59 /*
   60  * Variables for DISTANCE mode.
   61  */
   63 extern float dc_distance_interval;
   64 
   65 
   66 /*
   67  * Variables for SURVEY mode.
   68  */
   70 extern float dc_survey_interval;
   71 
   73 extern float dc_gps_x, dc_gps_y;
   74 
   75 extern float dc_gps_next_dist;
   76 
   77 
   78 /*
   79  * Variables for CIRCLE mode.
   80  */
   82 extern float dc_circle_start_angle;
   83 
   85 extern float dc_circle_interval;
   86 
   87 extern float dc_circle_max_blocks;
   88 extern float dc_circle_last_block;
   89 
   90 
   92 extern float dc_cam_angle;
   93 extern uint8_t dc_cam_tracing;
   94 
   96 typedef enum {
   97   DC_GET_STATUS = 0,
   98 
   99   DC_HOLD = 13,
  100   DC_SHOOT = 32,
  101 
  102   DC_WIDER = 'w',
  103   DC_TALLER = 't',
  104 
  105   DC_UP = 'u',
  106   DC_DOWN = 'd',
  107   DC_CENTER = 'c',
  108   DC_LEFT = 'l',
  109   DC_RIGHT = 'r',
  110 
  111   DC_MENU = 'm',
  112   DC_HOME = 'h',
  113   DC_PLAY = 'p',
  114 
  115   DC_ON = 'O',
  116   DC_OFF = 'o',
  117 
  118 } dc_command_type;
  119 
  121 extern void dc_send_command(uint8_t cmd);
  122 
  124 typedef enum {
  125   DC_AUTOSHOOT_STOP = 0,
  126   DC_AUTOSHOOT_PERIODIC = 1,
  127   DC_AUTOSHOOT_DISTANCE = 2,
  128   DC_AUTOSHOOT_EXT_TRIG = 3,
  129   DC_AUTOSHOOT_SURVEY = 4,
  130   DC_AUTOSHOOT_CIRCLE = 5
  131 } dc_autoshoot_type;
  132 extern dc_autoshoot_type dc_autoshoot;
  133 
  135 void dc_send_shot_position(void);
  136 
  137 /* Macro value used to indicate a discardable argument */
  138 #ifndef DC_IGNORE
  139 #define DC_IGNORE FLT_MAX
  140 #endif
  141 
  142 /* Default values for buffer control */
  143 #ifndef DC_IMAGE_BUFFER
  144 #define DC_IMAGE_BUFFER 65535
  145 #endif
  146 
  147 /******************************************************************
  148  * FUNCTIONS
  149  *****************************************************************/
  150 
  152 extern void dc_init(void);
  153 
  155 extern void dc_periodic(void);
  156 
  168 extern uint8_t dc_distance(float interval);
  169 
  186 extern uint8_t dc_circle(float interval, float start);
  187 
  188 #define dc_Circle(interval) dc_circle(interval, DC_IGNORE)
  189 
  212 extern uint8_t dc_survey(float interval, float x, float y);
  213 
  214 #define dc_Survey(interval) dc_survey(interval, DC_IGNORE, DC_IGNORE)
  215 
  216 
  222 extern uint8_t dc_stop(void);
  223 
  224 #define dc_Stop(_) dc_stop()
  225 
  232 extern uint8_t dc_info(void);
  233 
  234 
  235 #endif // DC_H
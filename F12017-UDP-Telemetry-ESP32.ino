// =============================================
// Structures
// =============================================

// Telemetry UDP Packet structure
struct CarUDPData{
    float m_worldPosition[3]; // world co-ordinates of vehicle
    float m_lastLapTime;
    float m_currentLapTime;
    float m_bestLapTime;
    float m_sector1Time;
    float m_sector2Time;
    float m_lapDistance;
    byte  m_driverId;
    byte  m_teamId;
    byte  m_carPosition;     // UPDATED: track positions of vehicle
    byte  m_currentLapNum;
    byte  m_tyreCompound; // compound of tyre – 0 = ultra soft, 1 = super soft, 2 = soft, 3 = medium, 4 = hard, 5 = inter, 6 = wet
    byte  m_inPits;           // 0 = none, 1 = pitting, 2 = in pit area
    byte  m_sector;           // 0 = sector1, 1 = sector2, 2 = sector3
    byte  m_currentLapInvalid; // current lap invalid - 0 = valid, 1 = invalid
    byte  m_penalties;  // NEW: accumulated time penalties in seconds to be added

};

// Telemetry UDP Packet structure
struct UDPPacket{ 
    float m_time;
    float m_lapTime;
    float m_lapDistance;
    float m_totalDistance;
    float m_x;  // World space position
    float m_y;  // World space position
    float m_z;  // World space position
    float m_speed;  // Speed of car in MPH
    float m_xv; // Velocity in world space
    float m_yv; // Velocity in world space
    float m_zv; // Velocity in world space
    float m_xr; // World space right direction
    float m_yr; // World space right direction
    float m_zr; // World space right direction
    float m_xd; // World space forward direction
    float m_yd; // World space forward direction
    float m_zd; // World space forward direction
    float m_susp_pos[4];  // Note: All wheel arrays have the order:
    float m_susp_vel[4];  // RL, RR, FL, FR
    float m_wheel_speed[4];
    float m_throttle;
    float m_steer;
    float m_brake;
    float m_clutch;
    float m_gear;
    float m_gforce_lat;
    float m_gforce_lon;
    float m_lap;
    float m_engineRate;
    float m_sli_pro_native_support; // SLI Pro support
    float m_car_position; // car race position
    float m_kers_level; // kers energy left
    float m_kers_max_level; // kers maximum energy
    float m_drs;  // 0 = off, 1 = on
    float m_traction_control; // 0 (off) - 2 (high)
    float m_anti_lock_brakes; // 0 (off) - 1 (on)
    float m_fuel_in_tank; // current fuel mass
    float m_fuel_capacity;  // fuel capacity
    float m_in_pits;  // 0 = none, 1 = pitting, 2 = in pit area
    float m_sector; // 0 = sector1, 1 = sector2, 2 = sector3
    float m_sector1_time; // time of sector1 (or 0)
    float m_sector2_time; // time of sector2 (or 0)
    float m_brakes_temp[4]; // brakes temperature (centigrade)
    float m_tyres_pressure[4];  // tyres pressure PSI
    float m_team_info;  // team ID 
    float m_total_laps; // total number of laps in this race
    float m_track_size; // track size meters
    float m_last_lap_time;  // last lap time
    float m_max_rpm;  // cars max RPM, at which point the rev limiter will kick in
    float m_idle_rpm; // cars idle RPM
    float m_max_gears;  // maximum number of gears
    float m_sessionType;  // 0 = unknown, 1 = practice, 2 = qualifying, 3 = race
    float m_drsAllowed; // 0 = not allowed, 1 = allowed, -1 = invalid / unknown
    float m_track_number; // -1 for unknown, 0-21 for tracks
    float m_vehicleFIAFlags;  // -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
    float m_era;                      // era, 2017 (modern) or 1980 (classic)
    float m_engine_temperature;   // engine temperature (centigrade)
    float m_gforce_vert;  // vertical g-force component
    float m_ang_vel_x;  // angular velocity x-component
    float m_ang_vel_y;  // angular velocity y-component
    float m_ang_vel_z;  // angular velocity z-component
    byte  m_tyres_temperature[4]; // tyres temperature (centigrade)
    byte  m_tyres_wear[4];  // tyre wear percentage
    byte  m_tyre_compound;  // compound of tyre – 0 = ultra soft, 1 = super soft, 2 = soft, 3 = medium, 4 = hard, 5 = inter, 6 = wet
    byte  m_front_brake_bias;         // front brake bias (percentage)
    byte  m_fuel_mix;                 // fuel mix - 0 = lean, 1 = standard, 2 = rich, 3 = max
    byte  m_currentLapInvalid;      // current lap invalid - 0 = valid, 1 = invalid
    byte  m_tyres_damage[4];  // tyre damage (percentage)
    byte  m_front_left_wing_damage; // front left wing damage (percentage)
    byte  m_front_right_wing_damage;  // front right wing damage (percentage)
    byte  m_rear_wing_damage; // rear wing damage (percentage)
    byte  m_engine_damage;  // engine damage (percentage)
    byte  m_gear_box_damage;  // gear box damage (percentage)
    byte  m_exhaust_damage; // exhaust damage (percentage)
    byte  m_pit_limiter_status; // pit limiter status – 0 = off, 1 = on
    byte  m_pit_speed_limit;  // pit speed limit in mph
    float m_session_time_left;  // NEW: time left in session in seconds 
    byte  m_rev_lights_percent;  // NEW: rev lights indicator (percentage)
    byte  m_is_spectating;  // NEW: whether the player is spectating
    byte  m_spectator_car_index;  // NEW: index of the car being spectated

    // Car data
    byte  m_num_cars;               // number of cars in data
    byte  m_player_car_index;         // index of player's car in the array
    CarUDPData  m_car_data[20];   // data for all cars on track

    float m_yaw;  // NEW (v1.8)
    float m_pitch;  // NEW (v1.8)
    float m_roll;  // NEW (v1.8)
    float m_x_local_velocity;          // NEW (v1.8) Velocity in local space
    float m_y_local_velocity;          // NEW (v1.8) Velocity in local space
    float m_z_local_velocity;          // NEW (v1.8) Velocity in local space
    float m_susp_acceleration[4];   // NEW (v1.8) RL, RR, FL, FR
    float m_ang_acc_x;                 // NEW (v1.8) angular acceleration x-component
    float m_ang_acc_y;                 // NEW (v1.8) angular acceleration y-component
    float m_ang_acc_z;                 // NEW (v1.8) angular acceleration z-component
};


// =============================================
// Includes and Defines
// =============================================

#include <WiFi.h>
#include <WiFiUdp.h>

#define ESP32_ONBOARD_LED 2

// Set LAN ssid and password
const char* ssid = "SSID";
const char* password = "PASSWORD";

WiFiUDP Udp;
unsigned int localUdpPort = 20777;  // local port to listen on
char incomingPacket[1289];  // buffer for incoming packets


// =============================================
// Setup
// =============================================

void setup()
{
  // Initialize serial comm
  Serial.begin(115200);
  
  // Connect to Wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  // Configure UDP settings
  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
  
  // Define ESP32 built in LED as output
  pinMode(ESP32_ONBOARD_LED, OUTPUT);
  digitalWrite(ESP32_ONBOARD_LED, LOW);
}


// =============================================
// Loop
// =============================================

void loop()
{
  // Parse UDP packet
  int packetSize = Udp.parsePacket();
  
  // if there is incoming UDP packets, process
  if (packetSize) 
  {
    
    // -------------------------------------------------
    // receive incoming UDP packets
    
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 1289);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    
    UDPPacket *tmp_pckt = (UDPPacket *) incomingPacket;

    
    // -------------------------------------------------
    // Application: use packet information

    Serial.println("==================================");
    
    float m_lapTime = tmp_pckt -> m_lapTime;
    Serial.print("m_lapTime: ");
    Serial.println(m_lapTime);

    float m_speed = tmp_pckt -> m_speed;
    Serial.print("m_speed: ");
    Serial.println(m_speed);

    int gear = tmp_pckt -> m_gear;
    gear = gear-1;
    Serial.print("gear: ");
    Serial.println(gear);


    // -----------------------------------
    // DRS - ESP32 ONBOARD LED

    int m_drs = tmp_pckt -> m_drs;
    Serial.print("m_drs: ");
    Serial.println(m_drs);
    
    bool drs = (bool)m_drs; 

    if (drs) 
    {
      digitalWrite(ESP32_ONBOARD_LED, HIGH);
    }
    else
    {
      digitalWrite(ESP32_ONBOARD_LED, LOW);
    }
    
  }
}

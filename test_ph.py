import time
from pymavlink import mavutil


    

# Create the connection
# From topside computer
master = mavutil.mavlink_connection('udp:0.0.0.0:14550')


# Restart the ArduSub board !
# master.reboot_autopilot()

# Wait a heartbeat before sending commands
master.wait_heartbeat()

# define
exp_type = ''
enum_command = 65

master.mav.command_long_send(
    master.target_system,
    master.target_component,
    mavutil.mavlink.MAV_CMD_REQUEST_MESSAGE,
    # 512
    # mavutil.mavlink.MAV_CMD_GET_MESSAGE_INTERVAL,
    # 510
    0,                                       # confirmation
    227, 0, 0, 0, 0, 0, 0
)

while True:
    # Wait for ACK command
    ack_msg = master.recv_match(type='COMMAND_ACK', blocking=True)
    ack_msg = ack_msg.to_dict()
    if ack_msg['command'] != mavutil.mavlink.MAV_CMD_REQUEST_MESSAGE:
        continue
    # Print the ACK result !
    print(mavutil.mavlink.enums['MAV_RESULT'][ack_msg['result']].description)
    break

while True:
    try:
        print(master.recv_match(type='PH').to_dict())
    except:
        pass
    time.sleep(0.5)






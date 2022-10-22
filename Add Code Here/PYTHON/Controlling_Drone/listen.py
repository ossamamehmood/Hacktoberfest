from pymavlink import mavutil

the_connection=mavutil.mavlink_connection('udpin:localhost:14550')

the_connection.wait_heartbeat()
print("Heartbeat from system (system %u component %u)" %
      (the_connection.target_system, the_connection.target_component))

while True:
      message=the_connection.recv_match(blocking=True)
      print(message)
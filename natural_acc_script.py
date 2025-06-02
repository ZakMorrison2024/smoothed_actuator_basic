# Accelerate toward target direction
accel = 0.4
decel = 0.7

target_dx = self.dx
target_dy = self.dy

# Smooth only when accelerating (no sliding)
if target_dx != 0:
    self.smooth_dx += (target_dx - self.smooth_dx) * accel
else:
    self.smooth_dx *= decel  # Decelerate fast

if target_dy != 0:
    self.smooth_dy += (target_dy - self.smooth_dy) * accel
else:
    self.smooth_dy *= decel

# Apply to movement
self.player.x_move = self.smooth_dx * player_speed
self.player.y_move = self.smooth_dy * player_speed

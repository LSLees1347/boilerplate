


















































































use macroquad::prelude::*;
use rand::Rng;

struct GameObject {
    position: Vec2,
    size: f32,
    color: Color,
}

#[macroquad::main("Enhanced Game")]
async fn main() {
    // Player properties
    let mut player = GameObject {
        position: vec2(400.0, 300.0),
        size: 50.0,
        color: BLUE,
    };

    // Target properties
    let mut target = GameObject {
        position: vec2(rand::thread_rng().gen_range(50.0..750.0), rand::thread_rng().gen_range(50.0..550.0)),
        size: 30.0,
        color: RED,
    };

    let player_speed = 300.0;
    let mut score = 0;

    loop {
        clear_background(LIGHTGRAY);

        // Update player position based on input
        if is_key_down(KeyCode::W) {
            player.position.y -= player_speed * get_frame_time();
        }
        if is_key_down(KeyCode::S) {
            player.position.y += player_speed * get_frame_time();
        }
        if is_key_down(KeyCode::A) {
            player.position.x -= player_speed * get_frame_time();
        }
        if is_key_down(KeyCode::D) {
            player.position.x += player_speed * get_frame_time();
        }

        // Restrict player to the game area
        player.position.x = player.position.x.clamp(0.0, screen_width() - player.size);
        player.position.y = player.position.y.clamp(0.0, screen_height() - player.size);

        // Check for collision between player and target
        if player.position.distance(target.position) < (player.size + target.size) / 2.0 {
            score += 1;
            target.position = vec2(
                rand::thread_rng().gen_range(50.0..screen_width() - 50.0),
                rand::thread_rng().gen_range(50.0..screen_height() - 50.0),
            );
        }

        // Draw the player
        draw_rectangle(
            player.position.x,
            player.position.y,
            player.size,
            player.size,
            player.color,
        );

        // Draw the target
        draw_rectangle(
            target.position.x,
            target.position.y,
            target.size,
            target.size,
            target.color,
        );

        // Draw the score
        draw_text(
            &format!("Score: {}", score),
            20.0,
            30.0,
            40.0,
            DARKGRAY,
        );

        // Draw instructions
        draw_text(
            "comp error",
            20.0,
            screen_height() - 20.0,
            30.0,
            DARKGRAY,
        );

        next_frame().await;
    }
}

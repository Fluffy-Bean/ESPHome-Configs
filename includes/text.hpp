// https://community.home-assistant.io/t/centering-text-when-using-multiple-printf

int GetTextBounds(esphome::display::Display* it, esphome::font::Font *font, const char *buffer)
{
    int calculated_x = 0;
    int calculated_y = 0;
    int calculated_width = 0;
    int calculated_height = 0;
    it->get_text_bounds(0, 0, buffer, font, TextAlign::TOP_LEFT, &calculated_x, &calculated_y, &calculated_width, &calculated_height);
    return calculated_width;
}

int GetTextWidth(esphome::display::Display* it, esphome::font::Font *font, const char* formatting, const char *raw_text){
    char temp_buffer[80];
    sprintf(temp_buffer, formatting, raw_text);
    return GetTextBounds(it, font, temp_buffer);
}

int GetTextWidth(esphome::display::Display* it, esphome::font::Font *font, const char* formatting, esphome::ESPTime time){
    auto c_tm = time.to_c_tm();
    size_t buffer_length = 80;
    char temp_buffer[buffer_length];
    strftime(temp_buffer, buffer_length, formatting, &c_tm);
    return GetTextBounds(it, font, temp_buffer);
}

int GetTextWidth(esphome::display::Display* it, esphome::font::Font *font, const char* formatting, const int raw_int){
    char temp_buffer[80];
    sprintf(temp_buffer, formatting, raw_int);
    return GetTextBounds(it, font, temp_buffer);
}

int GetTextWidth(esphome::display::Display* it, esphome::font::Font *font, const char* formatting, const float raw_float){
    char temp_buffer[80];
    sprintf(temp_buffer, formatting, raw_float);
    return GetTextBounds(it, font, temp_buffer);
}

#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>

class DrawUpdateRawData {
public:
    static constexpr std::size_t header_length = 4;
    static constexpr std::size_t max_body_length =
        1920 * 1200 * (4 + sizeof(bool) + 2 * sizeof(int)) /*image max size*/ + 27 /*date YYYY/MM/DD/HH/MM/SS/MS/+UTC*/;

    DrawUpdateRawData();

    const char* data() const;

    char* data();

    std::size_t length() const;

    const char* body() const;

    char* body();

    std::size_t body_length() const;

    void body_length(std::size_t new_length);

    bool decode_header();

    void encode_header();
private:
    char data_[header_length + max_body_length];
    std::size_t body_length_;
};

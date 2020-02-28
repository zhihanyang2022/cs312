/******************************************************
hw412_gmnames.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw412
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-02
TIME: 21-13-39
******************************************************/

#include <iostream>
#include <string>
#include <vector>

void print_divider(const std::string category)
{
    const char kCHAR_TO_PRINT = '=';
    const int kNUM_CHARS = 45;
    const int kNUM_CHARS_FRONT = 7;
    const int kNUM_CHARS_PAD = 2;

    if (category.size() == 0) {
        std::cout << std::string(kNUM_CHARS, kCHAR_TO_PRINT) << std::endl;
    } else {
        std::cout 
        << std::string(kNUM_CHARS_FRONT, kCHAR_TO_PRINT)
        << " "
        << category
        << " "
        << std::string(kNUM_CHARS - kNUM_CHARS_FRONT - category.size() - kNUM_CHARS_PAD, kCHAR_TO_PRINT)
        << std::endl;
    }
}

int main() {

    const std::vector<std::string> kCATEGORIES = {
        "Piano",
        "Chromatic Percussion",
        "Organ",
        "Guitar",
        "Bass",
        "Strings",
        "Ensemble",
        "Brass",
        "Reed",
        "Pipe",
        "Synth Lead",
        "Synth Pad",
        "Synth Effects",
        "Ethnic",
        "Percussive",
        "Sound Effects",
    };

    const std::vector<std::string> kNAMES = {
        "Acoustic Grand Piano",
        "Bright Acoustic Piano",
        "Electric Grand Piano",
        "Honky-tonk Piano",
        "Electric Piano 1",
        "Electric Piano 2",
        "Harpsichord",
        "Clavinet",
        "Celesta",
        "Glockenspiel",
        "Music Box",
        "Vibraphone",
        "Marimba",
        "Xylophone",
        "Tubular Bells",
        "Dulcimer",
        "Drawbar Organ",
        "Percussive Organ",
        "Rock Organ",
        "Church Organ",
        "Reed Organ",
        "Accordion",
        "Harmonica",
        "Tango Accordion",
        "Acoustic Guitar (nylon)",
        "Acoustic Guitar (steel)",
        "Electric Guitar (jazz)",
        "Electric Guitar (clean)",
        "Electric Guitar (muted)",
        "Overdriven Guitar",
        "Distortion Guitar",
        "Guitar harmonics",
        "Acoustic Bass",
        "Electric Bass (finger)",
        "Electric Bass (pick)",
        "Fretless Bass",
        "Slap Bass 1",
        "Slap Bass 2",
        "Synth Bass 1",
        "Synth Bass 2",
        "Violin",
        "Viola",
        "Cello",
        "Contrabass",
        "Tremolo Strings",
        "Pizzicato Strings",
        "Orchestral Harp",
        "Timpani",
        "String Ensemble 1",
        "String Ensemble 2",
        "SynthStrings 1",
        "SynthStrings 2",
        "Choir Aahs",
        "Voice Oohs",
        "Synth Voice",
        "Orchestra Hit",
        "Trumpet",
        "Trombone",
        "Tuba",
        "Muted Trumpet",
        "French Horn",
        "Brass Section",
        "SynthBrass 1",
        "SynthBrass 2",
        "Soprano Sax",
        "Alto Sax",
        "Tenor Sax",
        "Baritone Sax",
        "Oboe",
        "English Horn",
        "Bassoon",
        "Clarinet",
        "Piccolo",
        "Flute",
        "Recorder",
        "Pan Flute",
        "Blown Bottle",
        "Shakuhachi",
        "Whistle",
        "Ocarina",
        "Lead 1 (square)",
        "Lead 2 (sawtooth)",
        "Lead 3 (calliope)",
        "Lead 4 (chiff)",
        "Lead 5 (charang)",
        "Lead 6 (voice)",
        "Lead 7 (fifths)",
        "Lead 8 (bass + lead)",
        "Pad 1 (new age)",
        "Pad 2 (warm)",
        "Pad 3 (polysynth)",
        "Pad 4 (choir)",
        "Pad 5 (bowed)",
        "Pad 6 (metallic)",
        "Pad 7 (halo)",
        "Pad 8 (sweep)",
        "FX 1 (rain)",
        "FX 2 (soundtrack)",
        "FX 3 (crystal)",
        "FX 4 (atmosphere)",
        "FX 5 (brightness)",
        "FX 6 (goblins)",
        "FX 7 (echoes)",
        "FX 8 (sci-fi)",
        "Sitar",
        "Banjo",
        "Shamisen",
        "Koto",
        "Kalimba",
        "Bag pipe",
        "Fiddle",
        "Shanai",
        "Tinkle Bell",
        "Agogo",
        "Steel Drums",
        "Woodblock",
        "Taiko Drum",
        "Melodic Tom",
        "Synth Drum",
        "Reverse Cymbal",
        "Guitar Fret Noise",
        "Breath Noise",
        "Seashore",
        "Bird Tweet",
        "Telephone Ring",
        "Helicopter",
        "Applause",
        "Gunshot"
    };

    print_divider("");
    std::cout << std::endl << "General MIDI instrument patch numbers" << std::endl << std::endl;
    
    int name_counter = 0;
    int current_category_idx = 0;
    for (auto iter : kNAMES) {
        if (name_counter % 8 == 0) {
            print_divider(kCATEGORIES[current_category_idx] + " (" + std::to_string(name_counter) + "-" + std::to_string(name_counter+8) + ")");
            ++current_category_idx;
        }
        std::string name_counter_str = std::to_string(name_counter);
        std::cout << name_counter_str << std::string(6 - name_counter_str.size(), ' ') << iter << std::endl;
        ++name_counter;
    }

}
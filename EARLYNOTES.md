			Hardware
Controller: generate MIDI signal based on human action (or in this case, heartbeat input) 

Synthesizer: Takes MIDI signal IN, and makes sound, light, etc. 


---------
					Data/bytes (31,250 bytes/second)
Command/Status: 128 or greater (0x80 to 0xFF)
	MSB = 1
	note on, note off, pitch bend, etc
	First nibble = type of message (eg note on, pitch bend, etc)
	Second nibble = which channel message is being sent on (there are 16 total) 

Data: 127 or less (0x00 to 0x7F)
	MSB = 0
	pitch, velocity, loudness, amount of pitch bend

---

internal MIDI bridge utility to route MIDI to the virtual synths that you want to use live on the same laptop
---
Controller:
	(MSP?)
	Send MIDI to loopMIDI as destination

Middleware: 
	(serial.print to send to PC?)
	(serial to MIDI converter?) 


Synth: Reaper Midi -> Virtual Instrument? 
	Reaper Input: Enable loopMIDI for MIDI devices input
			  Create dummy track to receive loopMIDI control codes
			  Arm track, choose loopMIDI as the FX in Source

		(ReLearn?) 

Get bio input. Get it reading on serial monitor. Convert serial to MIDI. take MIDI as loopMIDI input in Reaper. 
----

Prototypes: biometric inputs to LED brightness or on/off or frequency/velocity 

# Macropadski
A 10-key macro pad built using a Teensy 3.2, Cherry MX (or compatible) switches, and a 3D-printed case.

### The Switches

This macro pad makes use of Cherry MX-fit mechanical keyboard switches. Other switches like Gateron or Kailh should fit just fine. 

### The Case

Files for the case have been included in the `case/` folder. There are both STLs for all 3 pieces, and a STEP file for further customisation.

The case was designed in Fusion 360 for printing on a Prusa i3 Mk2.5S. It requires support materials for the Teensy tray and bottom screw holes. Assembly requires 8 M3x6 screws (Hex or Phillips head are fine). I printed the case in PLA and top plate in PETG.

### Wiring

I haven't produced any wiring diagrams for this yet. I did follow [a guide for building your own mechanical keyboard](https://matt3o.com/hand-wiring-a-custom-keyboard/) for the gist of the construction. You'll need 10 1N4148 Diodes (one per switch) to wire everything together. Configure the Arduino sketch to use the correct pins on your Teensy 3.2.

### License

```
Copyright 2019 David Richardson

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
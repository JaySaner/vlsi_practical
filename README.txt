VLSI DESIGN - 10 EXAM PRACTICALS
================================

Each experiment folder contains:
- Design Verilog source (.v)
- Xilinx ISE Test Fixture / testbench source (_tbw.v)

File naming:
Exp01_Full_Adder/
  Exp01_FA_Beh.v
  Exp01_FA_Struct.v
  Exp01_FA_tbw.v
(and similarly for the remaining experiments)

HOW TO USE IN XILINX ISE
1. Create/open a project.
2. Add the design .v file(s) under Design Sources.
3. Add the *_tbw.v file under Simulation Sources.
4. Set the testbench module as the simulation top.
5. Run Simulate Behavioral Model.
6. Check clk and output signals in the waveform for sequential circuits.

IMPORTANT
- All designs use Verilog-2001 syntax for compatibility with Xilinx ISE 14.7.
- The testbenches use the module names and port names in the corresponding design files.
- For experiments with more than one design style, the same testbench checks both versions.
- Exp 6 is a 3-bit ALU, matching the handwritten exam practical list.
- Exp 9 uses cnt=1 for UP and cnt=0 for DOWN. The 4-bit counter wraps modulo 16.
- Exp 10 contains four separate shift-register designs and four separate testbenches.
- Reset is active-high in designs that include rst.
- For Exp 10, SISO and SIPO shift the incoming bit toward the MSB; PISO shifts MSB-first.

EXPERIMENT INDEX
01 Full Adder (Behavioral and Structural)
02 Full Adder using Two Half Adders (Structural)
03 Full Subtractor
04 8:1 MUX (Behavioral case and Structural)
05 3:8 Decoder (Behavioral case and Structural)
06 3-bit ALU (Behavioral)
07 D Flip-Flop (Behavioral)
08 T Flip-Flop (Behavioral)
09 4-bit Up-Down Counter (Behavioral)
10 SISO, SIPO, PISO, PIPO Shift Registers (Behavioral)

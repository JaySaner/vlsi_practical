`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date:
// Design Name:
// Module Name:
// Project Name:
// Target Device:
// Tool versions:
// Description: Verilog Test Fixture
//
// Dependencies:
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
////////////////////////////////////////////////////////////////////////////////

module Exp06_ALU_tbw;
reg [2:0] A, B, sel;
wire [2:0] Y;
wire Cout;

ALU_3bit uut(.A(A), .B(B), .sel(sel), .Y(Y), .Cout(Cout));

initial begin
    A=3'b010; B=3'b100;
    sel=3'b000; #100;
    sel=3'b001; #100;
    sel=3'b010; #100;
    sel=3'b011; #100;
    sel=3'b100; #100;
    sel=3'b101; #100;
    sel=3'b110; #100;
    sel=3'b111; #100;
    // Add stimulus here
end
endmodule

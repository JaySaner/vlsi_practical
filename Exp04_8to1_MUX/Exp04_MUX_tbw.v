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

module Exp04_MUX_tbw;
reg [7:0] I;
reg [2:0] S;
wire Y_beh, Y_struct;

mux_8_1_beh U1(.I(I), .S(S), .Y(Y_beh));
mux_8_1_struct U2(.I(I), .S(S), .Y(Y_struct));

initial begin
    I=8'b10101010;
    S=3'b000; #100;
    S=3'b001; #100;
    S=3'b010; #100;
    S=3'b011; #100;
    S=3'b100; #100;
    S=3'b101; #100;
    S=3'b110; #100;
    S=3'b111; #100;
    // Add stimulus here
end
endmodule

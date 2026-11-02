module sipo(
    input clk, input din,
    output reg [3:0] q
);
always @(posedge clk)
    q <= {din, q[3:1]};
endmodule

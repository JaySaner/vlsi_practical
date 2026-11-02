module UP_DOWN(
    input clk,
    input rst,
    input cnt,
    output reg [3:0] Q
);
always @(posedge clk or posedge rst) begin
    if (rst)
        Q <= 4'b0000;
    else if (cnt)
        Q <= Q + 1'b1;
    else
        Q <= Q - 1'b1;
end
endmodule

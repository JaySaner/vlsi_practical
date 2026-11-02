module siso(
    input clk, input rst, input din,
    output reg q
);
reg [3:0] s;
always @(posedge clk) begin
    if (rst) begin
        s <= 4'b0000;
        q <= 1'b0;
    end else begin
        s <= {s[2:0], din};
        q <= s[3];
    end
end
endmodule

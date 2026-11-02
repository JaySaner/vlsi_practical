module piso(
    input clk, input rst, input load,
    input [3:0] din,
    output reg q
);
reg [3:0] s;
always @(posedge clk or posedge rst) begin
    if (rst) begin
        s <= 4'b0000;
        q <= 1'b0;
    end else if (load) begin
        s <= din;
    end else begin
        q <= s[3];
        s <= {s[2:0], 1'b0};
    end
end
endmodule

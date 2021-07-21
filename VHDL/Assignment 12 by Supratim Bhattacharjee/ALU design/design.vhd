library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity alu is
port(
  x: in signed(3 downto 0);
  y: in signed(3 downto 0);
  s: in signed(2 downto 0);
  op: out signed(3 downto 0);
);
end alu;

architecture behavioral of alu is
begin
  process(x,y,s)
  begin
    if(s="000") then
      op<=x+y;
    elsif(s="001") then
      op<=x-y;
    elsif(s="010") then
      op<=x-1;
    elsif(s="011") then
      op<=x+1;
    elsif(s="100") then
      op<=x and y;
    elsif(s="101") then
      op<=x or y;
    elsif(s="110") then
      op<=not(x);
    elsif(s="111") then
      op<=x xor y;
    else
      op<="1111";
    end if;
  end process;
end behavioral;
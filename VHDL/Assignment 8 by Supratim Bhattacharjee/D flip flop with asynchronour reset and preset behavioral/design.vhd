library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity dff_with_rst_clr is
port(
  D: in std_logic;
  clk: in std_logic;
  pre: in std_logic;
  clr: in std_logic;
  O: out std_logic
  );
end dff_with_rst_clr;

architecture behavioral of dff_with_rst_clr is
begin
  process(D,clk,pre,clr)
  begin
    if(clr='0' and pre='0') then
      O<='X';
    elsif(pre='0') then
      O<='1';
    elsif(clr='0') then
      O<='0';
    elsif(clk'event and clk='1') then
      O<=D;
    end if;
  end process;
end behavioral;
library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is
component decoder38 is
port(
  s: in std_logic_vector(2 downto 0);
  ac_low: out std_logic_vector(7 downto 0);
  ac_high: out std_logic_vector(7 downto 0));
end component;

signal sel : std_logic_vector(2 downto 0);
signal out_high : std_logic_vector(7 downto 0);
signal out_low : std_logic_vector(7 downto 0);

begin
  DUT: decoder38 port map(sel,out_high,out_low);
process
begin
  sel<="000";
  wait for 1 ns;
  
  sel<="001";
  wait for 1 ns;
  
  sel<="010";
  wait for 1 ns;
  
  sel<="011";
  wait for 1 ns;
  
  sel<="100";
  wait for 1 ns;
  
  sel<="101";
  wait for 1 ns;
  
  sel<="110";
  wait for 1 ns;
  
  sel<="111";
  wait for 1 ns;
  wait;
  
  end process;
end tb;
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity testbench is
--empty
end testbench;

architecture alu_arch of testbench is

component alu is
port(
  x: in signed(3 downto 0);
  y: in signed(3 downto 0);
  s: in signed(2 downto 0);
  op: out signed(3 downto 0);
);
end component;

signal num1: signed(3 downto 0);
signal num2: signed(3 downto 0);
signal select_in: signed(2 downto 0);
signal output: signed(3 downto 0);

begin
  DUT: alu port map(num1,num2,select_in,output);
  
  process
    begin
      num1<="1101";
      num2<="0011";
      
      select_in<="000";
      wait for 1 ns;
      
      select_in<="001";
      wait for 1 ns;
      
      select_in<="010";
      wait for 1 ns;
      
      select_in<="011";
      wait for 1 ns;
      
      select_in<="100";
      wait for 1 ns;
      
      select_in<="101";
      wait for 1 ns;
      
      select_in<="110";
      wait for 1 ns;
      
      select_in<="111";
      wait for 1 ns;
      wait;
    end process;
end alu_arch;
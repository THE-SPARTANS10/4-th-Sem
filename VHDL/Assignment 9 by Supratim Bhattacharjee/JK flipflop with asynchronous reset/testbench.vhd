library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

component jkff_async_reset is
port(
  J: in std_logic;
  K: in std_logic;
  clk: in std_logic;
  reset: in std_logic;
  O: out std_logic
  );
end component;

signal J_in,K_in,clk_in,reset_in,O_out: std_logic;

begin
  DUT: jkff_async_reset port map(J_in,K_in,clk_in,reset_in,O_out);
  process
    begin
    for i in 1 to 6 loop
        clk_in<='0';
        wait for 1 ns;
        clk_in<='1';
        wait for 1 ns;
      end loop;
      wait;
    end process;
    
    process
      begin 
    J_in<='0';
    K_in<='1';
    reset_in<='1';
    wait for 1 ns;
    
    J_in<='1';
    K_in<='1';
    reset_in<='0';
    wait for 1 ns;
    
    J_in<='1';
    K_in<='1';
    reset_in<='1';
    wait for 1 ns;
    
    J_in<='1';
    K_in<='0';
    reset_in<='1';
    wait for 1 ns;
    
    J_in<='0';
    K_in<='1';
    reset_in<='1';
    wait for 1 ns;
    
    J_in<='1';
    K_in<='1';
    reset_in<='1';
    wait for 1 ns;
    
    J_in<='1';
    K_in<='0';
    reset_in<='0';
    wait for 1 ns;
    
    J_in<='1';
    K_in<='0';
    reset_in<='1';
    wait for 1 ns;
    
    J_in<='0';
    K_in<='1';
    reset_in<='0';
    wait for 1 ns;
    
    J_in<='0';
    K_in<='1';
    reset_in<='1';
    wait for 1 ns;
    
    J_in<='1';
    K_in<='1';
    reset_in<='0';
    wait for 1 ns;
    
    J_in<='1';
    K_in<='1';
    reset_in<='1';
    wait for 1 ns;
    wait;
  end process;
end tb;
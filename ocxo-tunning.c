void adjust_ocxo_per_second() {
    // 1. 测量频率误差
    float freq_error = measure_frequency_error();  // 单位：ppb
    
    // 2. 测量相位误差  
    int64_t phase_error = measure_phase_error();   // 单位：ns
    
    // 3. 计算控制量
    float control_voltage = calculate_control_voltage(freq_error, phase_error);
    
    // 4. 限制范围
    control_voltage = clamp(control_voltage, 0.0, 5.0);
    
    // 5. 输出到 DAC/PWM
    set_control_voltage(control_voltage);
}

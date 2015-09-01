Call:
glm(formula = Efficiency ~ System + Treatment + Lab + Experience + 
    Ability)

Deviance Residuals: 
      Min         1Q     Median         3Q        Max  
-0.061021  -0.021901  -0.009289   0.017966   0.203006  

Coefficients:
                     Estimate Std. Error t value Pr(>|t|)    
(Intercept)        -0.0784003  0.0232811  -3.368  0.00158 ** 
Systemxml-security -0.0103287  0.0131413  -0.786  0.43610    
Treatmentrandom     0.0408678  0.0130782   3.125  0.00315 ** 
Lablab2             0.0005354  0.0134652   0.040  0.96847    
Experiencemsc       0.0208320  0.0137561   1.514  0.13708    
Ability             0.0490092  0.0111127   4.410 6.57e-05 ***
---
Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1

(Dispersion parameter for gaussian family taken to be 0.002103959)

    Null deviance: 0.183689  on 49  degrees of freedom
Residual deviance: 0.092574  on 44  degrees of freedom
AIC: -158.69

Number of Fisher Scoring iterations: 2

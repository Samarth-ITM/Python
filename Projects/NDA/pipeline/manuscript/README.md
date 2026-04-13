# LaTeX Manuscript — Analytical Chemistry (ACS)

## Structure

```
manuscript/
├── main.tex          ← Main manuscript file
├── references.bib    ← BibTeX bibliography (25 references)
├── figures/          ← Place all figure files here (.pdf, .png, .eps)
│   ├── toc_graphic.png      (TOC graphic: 8.25 × 4.45 cm, 300 dpi, RGB)
│   ├── fig1_mean_spectra.*  (Figure 1: mean spectra TB vs NTM)
│   ├── fig2_preprocessing.* (Figure 2: preprocessing pipeline)
│   ├── fig3_boxplots.*      (Figure 3: biomarker distributions)
│   ├── fig4_pca.*           (Figure 4: PCA plot)
│   ├── fig5_benchmark.*     (Figure 5: ML benchmark AUROC)
│   ├── fig6_roc_confusion.* (Figure 6: ROC + confusion matrices)
│   └── fig7_shap.*          (Figure 7: SHAP beeswarm)
└── README.md
```

## Compilation

```bash
# Standard sequence (run from the manuscript/ folder):
pdflatex main.tex
bibtex main
pdflatex main.tex
pdflatex main.tex

# Or with latexmk (recommended):
latexmk -pdf main.tex

# Clean auxiliary files:
latexmk -c
```

## Journal: Analytical Chemistry (ACS)

| Setting | Value |
|---------|-------|
| Document class | `achemso` |
| Journal code | `ancham` |
| Manuscript type | `article` |
| Layout | `traditional` (double-spaced, single column) |
| Max words | 10,000 |
| Abstract | 80–250 words, no references |
| Keywords | 5–8 |
| TOC graphic | 8.25 × 4.45 cm, 300 dpi, RGB |
| Line numbers | Enabled (`\linenumbers`) |
| Bibliography style | `achemso` (automatic) |
| Citation format | Superscript numbers |

## Required LaTeX packages

Install via TeX Live or MiKTeX:
- `achemso` (core — includes natbib, geometry, setspace)
- `siunitx` (SI units)
- `booktabs` (professional tables)
- `graphicx` (figures)
- `lineno` (line numbers)
- `amsmath`, `amsfonts`, `amssymb` (mathematics)
- `hyperref` (links)
- `multirow`, `tabularx`, `array` (tables)

## TODOs before submission

### HIGH priority (required)
- [ ] Fill in author names, affiliations, corresponding author email
- [ ] Add MALDI-TOF instrument details (model, matrix, calibration, parameters)
- [ ] Add clinical gold standard used for diagnosis (culture, PCR, etc.)
- [ ] Fill in Table 1 (cohort demographics: age, sex, HIV, specimen type)
- [ ] Add ethics approval number and institution
- [ ] Run comparison vs standard MALDI Biotyper approach (section 3.5)
- [ ] Place actual figure files in `figures/` folder
- [ ] Create TOC graphic (8.25 × 4.45 cm)

### MEDIUM priority
- [ ] Report external validation cohort results separately (section 3.7)
- [ ] Complete PCA interpretation (Option A or B in Results 4.3)
- [ ] Add DeLong test p-value for AUROC comparison
- [ ] Add PPV/NPV values for operating point
- [ ] Fill in ExtraTrees test set metrics (bracketed values in Table 2)
- [ ] Complete SHAP analysis figure

### LOW priority
- [ ] Add GitHub URL for code repository
- [ ] Add Streamlit app URL
- [ ] Run hyperparameter optimization for final model
- [ ] Add funding/acknowledgment statement

## Overleaf

Upload the entire `manuscript/` folder to Overleaf. The `achemso`
package is pre-installed. Set the main document to `main.tex`.

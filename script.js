const navToggle = document.querySelector('.nav-toggle');
const primaryNav = document.querySelector('#primary-navigation');

if (navToggle && primaryNav) {
  navToggle.addEventListener('click', () => {
    const isExpanded = navToggle.getAttribute('aria-expanded') === 'true';
    navToggle.setAttribute('aria-expanded', String(!isExpanded));
    primaryNav.dataset.open = String(!isExpanded);
  });

  primaryNav.querySelectorAll('a').forEach((link) => {
    link.addEventListener('click', () => {
      navToggle.setAttribute('aria-expanded', 'false');
      primaryNav.dataset.open = 'false';
    });
  });
}

const yearEl = document.querySelector('#current-year');
if (yearEl) {
  yearEl.textContent = new Date().getFullYear();
}

const observerTargetSections = document.querySelectorAll('section[id]');
const navLinks = document.querySelectorAll('.site-nav a');

if ('IntersectionObserver' in window && observerTargetSections.length && navLinks.length) {
  const observer = new IntersectionObserver(
    (entries) => {
      entries.forEach((entry) => {
        if (entry.isIntersecting) {
          const id = entry.target.getAttribute('id');
          navLinks.forEach((link) => {
            if (link.getAttribute('href') === `#${id}`) {
              link.classList.add('is-active');
            } else {
              link.classList.remove('is-active');
            }
          });
        }
      });
    },
    {
      rootMargin: '-40% 0px -50% 0px',
    }
  );

  observerTargetSections.forEach((section) => observer.observe(section));
}
